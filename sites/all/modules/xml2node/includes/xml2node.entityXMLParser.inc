<?php

/**
 * @file
 * parses content from a xml file for usage in the later process
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */
class EntityXMLParser {

  // XMLReader - to read the xml file
  // SimpleXMLElement
  private $xml;

  // string - complete path to xml file to load
  private $filePath;

  // array - xml content converted to an array
  private $arrContent;

  // array
  private $dependencyTree;

  // constructor
  public function __construct($filePath) {
    $this->filePath = $filePath;
    $this->xml = new SimpleXMLElement(file_get_contents($filePath));
  }

  public function getDependencyTree() {
    return $this->dependencyTree;
  }


  static function getDependencyForEntity($dependencyTree, $record_id) {
    if (count($dependencyTree)) {
      foreach ($dependencyTree as $node) {
        if ($node['#id'] == $record_id) {
          if (count($node['#children'])) {
            return $node['#children'];
          }
        }
        else {
          return EntityXMLParser::getDependencyForEntity($node['#children'], $record_id);
        }
      }
    }
  }

  static function getDependencyIDArray($node, &$ids) {
    foreach ($node as $element) {
      if (count($element['#children'])) {
          EntityXMLParser::getDependencyIDArray($element['#children'], $ids);
      }
      $ids[] = $element['#id'];
    }
  }

  /**
   * Get content array
   * 
   * @return array
   */
  public function getContentArray() {
    return $this->arrContent;
  }

  /**
   * Return index of entity with recordID
   *
   * @param $recordID
   * @return int
   */
   public function getIndexByRecordID($recordID) {
     return count($this->xml->xpath('//entities/entity[@id="' . $recordID . '"]/preceding-sibling::*'));
   }

  /**
  * Get number of entities
  *
  * @return number of elements
  */
  public function getEntityCount() {
    if ($this->xml->children()->getName() == 'entity') {
      return $this->xml->children()->count();
    }
    return 0;
  }

  /**
   * Parse the XML content
   *
   * @param $index
   * @return bool
   */
  public function convertXMLRecord($index) {
    $this->dependencyTree = array();
    // get entity specified by index
    $entities = $this->xml->children();
    if ($this->xml->children()->getName() == 'entity') {
      if (isset($entities[$index])) {

        // we need to check dependencies between our entities first
        $dependencies = array();
        $id = (int)$entities[$index]->attributes()->id;

        $this->dependencyTree[$id] = array('#id' => $id, '#children' => array());
        $this->buildDependencyTree($entities, $id, $this->dependencyTree[$id]['#children']);
        return $this->buildXMLArrays($entities, $this->dependencyTree);

      }
    }

    return FALSE;
  }

  public function getAllXMLRecords() {
    $results = array();
    $entities = $this->xml->children();
    $entityCount = $this->getEntityCount();

    foreach ($entities as $entity) {
      $recordID = (int)$entity->attributes()->id;
      $this->convertXmlObjToArr($entity, $results[$recordID]);
    }

    return $results;
  }

  /**
   * Builds reference tree between entities.
   * Leafs of tree represents the entities which has to be build first.
   * Each upper level is dependant from lower levels.
   *
   *  Description:
   *  Function creates a nicely formed recursive array of entity dependencies.
   *  Array structure is formatted like this:
   *
   *    array(
   *      '#id' => 2,
   *      '#children' => array(
   *        array(
   *          '#id' => 1,
   *          '#children' => array(),
   *        ),
   *      ...
   *
   *   Function uses recursion to create the dependency tree
   *
   * @param SimpleXMLElement $entities
   * @param $index
   * @param $dependencies
   * @return
   */
  public function buildDependencyTree(SimpleXMLElement $entities, $index, &$dependencies) {
    $dependencies = array();
    if (!$entities instanceof SimpleXMLElement) {
      return;
    }

    // we are making assumption here, that only one ID is corresponding
    $entity = array_shift($entities->xpath('//entities/entity[@id="' . $index . '"]'));

    // get fields referencing to
    $fields = $entity->xpath('fields/field/lang/item/value[@ref_to]');
    // get properties referencing to entity
    $properties = $entity->xpath('properties/property[@ref_to]');

    if (count($properties)) {
    // take all our properties with reference attribute and save the entity dependency to array
      foreach ($properties as $delta => $property) {
        if (!empty($property->attributes()->ref_to)) {
          $ref_to_id = (int)$property->attributes()->ref_to;

          // set the id for this tree node
          $dependencies[$delta]['#id'] = $ref_to_id;
          // recurrently call this function to create leafs
          $this->buildDependencyTree($entities, $ref_to_id, $dependencies[$delta]['#children']);
        }
      }
    }

    if (!count($fields)) {
      return;
    }

    // take all our fields with reference attribute and save the entity dependency to array
    foreach ($fields as $delta => $field) {
      if (!empty($field->attributes()->ref_to)) {
        $ref_to_id = (int)$field->attributes()->ref_to;
        // set the id for this tree node
        $dependencies[$delta]['#id'] = $ref_to_id;
        // recurrently call this function to create leafs
        $this->buildDependencyTree($entities, $ref_to_id, $dependencies[$delta]['#children']);
      }
    }
  }

  /**
   * Function builds entity data based on dependency tree.
   * Function starts building from leafs and moves up to the tree root.
   *
   * @param $entities
   * @param $dependencies
   * @return void
   */
  private function buildXMLArrays($entities, $dependencies) {
    if (count($dependencies)) {
      foreach ($dependencies as $dependency) {
        if (count($dependency['#children'])) {
          $this->buildXMLArrays($entities, $dependency['#children']);
        }

        $entity = array_shift($entities->xpath('//entities/entity[@id="' . $dependency['#id'] . '"]'));
        $this->convertXmlObjToArr($entity, $this->arrContent[$dependency['#id']]);
      }
    }
  }

  /**
   * Converts a SimpleXMLElement into an array
   *
   * @param $entity
   *  the SimpleXMLElement object
   * @param $arr
   *  the array to store the content
   * @return bool
   */
  private function convertXmlObjToArr($entity, &$arr) {

    $nextIdx = count($arr);

    $arr[$nextIdx] = array();
    $arr[$nextIdx]['#name'] = drupal_strtolower((string) $entity->getName());
    $arr[$nextIdx]['#attributes'] = array();
    
    $attributes = $entity->attributes();
    foreach ($attributes as $attributeName => $attributeValue) {
      $arr[$nextIdx]['#attributes'][drupal_strtolower(trim((string) $attributeName))] = trim((string) $attributeValue);
    }

    $text = (string) $entity;
    $text = trim($text);

    $entities = EntityXMLParser::entitiesToReplace();
    $text = str_replace($entities['search'], $entities['replace'], $text);
    $text = html_entity_decode($text, ENT_COMPAT, 'UTF-8');
    
    if (drupal_strlen($text) > 0) {
      $arr[$nextIdx]['#text'] = $text;
    }
    
    $arr[$nextIdx]['#children'] = array();
    $children = $entity->children();
    
    foreach ($children as $child) {
      $this->convertXmlObjToArr($child, $arr[$nextIdx]['#children']);
    }

    return TRUE;
  }
  
  /**
   * Returns an array with utf-8 entities and the HTML replacement
   * @return array
   */
  public static function entitiesToReplace() {
    $entities['search'] = array();
    $entities['replace'] = array();
    
    $entities['search'][] = '&apos;'; // &apos; is not supported from IE
    $entities['replace'][] = '&#39;';
    
    $entities['search'][] = '&#x96;';
    $entities['replace'][] = '&ndash;';
    
    $entities['search'][] = '&#x84;';
    $entities['replace'][] = '&bdquo;';
    
    $entities['search'][] = '&#x93;';
    $entities['replace'][] = '&ldquo;';
    
    $entities['search'][] = '&#x94;';
    $entities['replace'][] = '&rdquo;';
    
    $entities['search'][] = '&#x92;';
    $entities['replace'][] = '&rsquo;';
    
    $entities['search'][] = '&#x91;';
    $entities['replace'][] = '&rsquo;';
    
    $entities['search'][] = '&#x82;';
    $entities['replace'][] = '&sbquo;';
        
    $entities['search'][] = '&#x85;';
    $entities['replace'][] = '&hellip;';
    
    $entities['search'][] = '&#x97;';
    $entities['replace'][] = '&mdash;';
        
    return $entities;
  }
}