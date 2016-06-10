<?php

/**
 * @file
 * maps original content to Drupal content type fields
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */
class EntityXMLMapper {

  // property declarations
  // array - content read from file

  private $entity = array();
  private $requirements = array();


  /**
   * Get entity
   * @return array
   */
  public function getEntity() {
    return $this->entity;
  }

  /**
   * @param $requirements
   * @return void
   */
  public function setRequirements($requirements) {
    $this->requirements = $requirements;
  }

  /**
   * Get requirement
   * @param $recordID
   * @return bool
   */
  public function getRequirement($recordID) {

    if (is_array($this->requirements[$recordID])
        && isset($this->requirements[$recordID]['xid'])
        && isset($this->requirements[$recordID]['entity'])) {
      return $this->requirements[$recordID]['entity'];
    }
    elseif (isset($this->requirements[$recordID])) {
      return $this->requirements[$recordID];
    }
    return FALSE;
  }

  /**
   * Check for entity based on existing recordID and file
   *
   * @param $recordID
   * @param $filePath
   * @return array|bool
   *  Return entity if present, false if not
   */
  static function checkExistingEntity($recordID, $filePath) {
    $query = db_select('xml_to_node', 'xtn')
      ->condition('rid', $recordID)
      ->condition('file', $filePath)
      ->fields('xtn', array('eid', 'entity_type', 'xid'));

    $result = $query->execute()->fetch();

    if (!empty($result)) {

      $entity_info = entity_get_info($result->entity_type);
      $callback = $entity_info['load hook'];

      //taxonomy_term_load()
      return array(
        'xid' => $result->xid,
        'entity' => $callback($result->eid),
      );
    }

    return FALSE;
  }

  /**
   * Create query for selecting entities
   * @param $entityData
   * @return EntityFieldQuery|null
   */
  public function buildEntityQuery($entityData) {
    $conditions = NULL;
    foreach ($entityData['#children'] as $element) {

      if ($element['#name'] == 'conditions') {
        $conditions = $element;
      }
    }

    if (empty($conditions)) {
      return NULL;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $entityData['#attributes']['name'])
          ->entityCondition('bundle', $entityData['#attributes']['type']);

    foreach ($conditions['#children'] as $condition) {
      switch ($condition['#attributes']['type']) {
        case 'property':
          $query->propertyCondition($condition['#attributes']['name'], $condition['#text']);
          break;
        case 'field':
          $column = isset($condition['#attributes']['column']) ? $condition['#attributes']['column'] : NULL;
          $operator = isset($condition['#attributes']['operator']) ? $condition['#attributes']['operator'] : NULL;
          $delta = isset($condition['#attributes']['delta']) ? $condition['#attributes']['delta'] : NULL;
          $language = isset($condition['#attributes']['lang']) ? $condition['#attributes']['lang'] : NULL;

          $query->fieldCondition($condition['#attributes']['name'], $column, $condition['#text'], $operator, $delta, $language);
          break;
      }
    }

    return $query;
  }

  /**
   * Method transforming data array into Drupal entity
   * 
   * @param $entityData
   * @param $filePath
   * @param $entity
   * @return void
   */
  public function buildEntity($entityData, $filePath, $entity = NULL) {
    if (!empty($entity)) {
      $this->entity = $entity;
      $update = TRUE;
    }
    else {
      $this->entity = new stdClass();
      $update = FALSE;
    }

    // Set up meta information about entity
    $meta = array(
      'entity_name' => $entityData['#attributes']['name'],
      'entity_bundle' => $entityData['#attributes']['type'],
      'id' => $entityData['#attributes']['id'],
      'action' => !empty($entityData['#attributes']['action']) ? $entityData['#attributes']['action'] : 'c',
      'key' => !empty($entityData['#attributes']['key']) ? $entityData['#attributes']['action'] : '',
      'update' => $update,
    );

    $this->entity->meta = $meta;

    // fill up the values array
    foreach ($entityData['#children'] as $element) {
      switch ($element['#name']) {
        case 'properties':
          foreach ($element['#children'] as $property) {
            $this->processProperty($property, $this->entity);
          }
          break;
        case 'fields':
          foreach ($element['#children'] as $field) {
            $this->processField($field, $this->entity);
          }
          break;
        default:
          break;
      }
    }
  }

  /**
   * Process property data array
   *
   * @param $property
   * @param $entity
   * @return void
   */
  function processProperty($property, &$entity) {
    // check if ref_to attribute  is set
    if (isset($property['#attributes']['ref_to'])) {
      $ref_to = $property['#attributes']['ref_to'];
      $ref_property = $property['#attributes']['ref_property'];
      //just to make sure we have needed dependency
      if (($requirement = $this->getRequirement($ref_to))) {

        $entity->$property['#attributes']['name'] = $requirement->$ref_property;
      }
      else {
        // error - no dependency
        watchdog('x2n', t('Required entity missing'), array('entity' => $entity), WATCHDOG_ERROR);
      }
    }
    elseif (isset($property['#attributes']['file'])) {
      $field_name = $property['#attributes']['belongs_to_field'];
      $entity_name = $property['#attributes']['belongs_to_entity'];
      $bundle_name = $property['#attributes']['belongs_to_bundle'];

      $instance_info =  field_info_instance($entity_name, $field_name, $bundle_name);
      $path = 'public://';
      if(isset($instance_info['settings']['file_directory'])) {
        $path .= $instance_info['settings']['file_directory'];
      }

      if (!drupal_realpath($property['#attributes']['file'])) {
        // external url
        $tempPath = xml2node_download_file_to_temp($property['#attributes']['file'], $property['#attributes']['file_name']);
        $entity->uri = file_unmanaged_move($tempPath, $path);

      } else if (file_exists(drupal_realpath($property['#attributes']['file'])))  {
        //internal uri
        $entity->uri = $property['#attributes']['file'];
        $fid = db_select('file_managed', 'fm')
          ->fields('fm', array('fid'))
          ->condition('fm.uri', $entity->uri)
          ->execute()->fetchColumn();

        // File already exists and is managed
        // We are setting entity id in order to update the image, instead of inserting it and
        // violating 'unique' condition on uri column
        if ($fid) {
           $entity->fid = $fid;
        }
      } else {
        // error - no file
        watchdog('x2n', t('File on path !uri not found!', array('!uri' => $entity->uri)), array('entity' => $entity), WATCHDOG_ERROR);
      }

      $entity->filename = $property['#attributes']['file_name'];
      $entity->filemime = file_get_mimetype($entity->uri);
      $entity->status = FILE_STATUS_PERMANENT;
    }
    else {
      // property is not a reference, just assigning element text
      $entity->$property['#attributes']['name'] = $property['#text'];
    }
  }

  /**
   * Process field data array
   *
   * @param $field
   * @param &$entity
   * @return void
   */
  function processField($field, &$entity) {
    $tmpArray = array();
    $field_name = $field['#attributes']['name'];

    foreach ($field['#children'] as $language) {
      $lang = $language['#attributes']['name'];
      $tmpArray[$lang] = array();
      // Process field items form selected language
      $this->processFieldLanguage($language, $tmpArray[$lang]);
    }


    $entity->$field_name = $tmpArray;
  }

  /**
   * Process field language data array
   *
   * @param $language
   * @param $tmpArray
   * @return void
   */
  function processFieldLanguage($language, &$tmpArray) {
    foreach ($language['#children'] as $delta => $item) {
      $tmpArray[$delta] = array();
      $this->processFieldItem($item, $tmpArray[$delta]);
    }
  }

  /**
   * Process field language items data array
   *
   * @param $item
   * @param $tmpArray
   * @return void
   */
  function processFieldItem($item, &$tmpArray) {
      foreach ($item['#children'] as $value) {
        $name = $value['#attributes']['name'];
        $this->processFieldValue($value, $tmpArray[$name]);
      }
  }

  /**
   * Finally assign the value to field item
   *
   * @param $value
   * @param $tmpArray
   * @return void
   */
  function processFieldValue($value, &$tmpArray) {

    // check if ref_to attribute is set
    if (isset($value['#attributes']['ref_to'])) {
      $ref_to = $value['#attributes']['ref_to'];
      $ref_property = $value['#attributes']['ref_property'];

      // just to make sure we have needed dependency
      if (($requirement = $this->getRequirement($ref_to)) && empty($tmpArray)) {
        $tmpArray = $requirement->$ref_property;
      }
      else {
        // error - required dependency
        watchdog('x2n', t('Required entity missing'), array('field' => $value), WATCHDOG_ERROR);
      }
    }
    else {
      // property is not a reference, just assigning element text
      $tmpArray = $value['#text'];
    }
  }
}

