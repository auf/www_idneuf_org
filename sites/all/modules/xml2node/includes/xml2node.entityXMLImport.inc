<?php
/**
 * @file
 * Handles import - importa manager.
 *
 * Takes care of cooperation between parser and mapper and performing actions on entities
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */

class entityXMLImport {

  private $mapper;
  private $parser;

  private $filePath;

  public function __construct($filePath) {
    $this->filePath = $filePath;
    $this->parser = new EntityXMLParser($this->filePath);
    $this->mapper = new EntityXMLMapper();
  }
  
  /**
   * @param array $recordIDs
   * @param string $method
   * @return void
   */
  public function import($recordIDs = array(), $method = XML2NODE_METHOD_BATCH) {

    if (empty($recordIDs)) {
      $recordIDs = array_keys($this->parser->getAllXMLRecords());
      $recordsCount = count($recordIDs);
    } else {
      $recordsCount = count($recordIDs);
    }
    
    switch ($method) {
      case XML2NODE_METHOD_BATCH:
        $batch = array(
          'finished' => 'xml2node_import_node_finished',
          'title' => format_plural($recordsCount, 'importing 1 entity', 'importing @count entities'),
          'init_message' => t('Initializing entity import'),
          'progress_message' => t('processed @current of @total entities'),
          'error_message' => t('An error occured while importing entities'),
          'file' => drupal_get_path('module', 'xml2node') . '/xml2node.batch.inc',
        );

        // create an operation for every record index
        foreach ($recordIDs as $recordID) {
          $index = $this->parser->getIndexByRecordID($recordID);
          $batch['operations'][] = array('entityXMLImport::importEntity', array($index, $this->filePath));
        }
        
        // run the batch job
        batch_set($batch);
        // if this function is not called from a form submit handler, run batch process
        batch_process();
          
        break;
      case XML2NODE_METHOD_QUEUE:
        $queue = DrupalQueue::get('xml2node_queue');
          // create a queue entry for every record index
          for ($index = 0; $index < $recordsCount; $index++) {
            $queue->createItem(array(
              'index' => $index,
              'xml' => $this->filePath,
            ));
          }
        break;
      default:
        break;
    }

  }

  static function importEntity($index, $filePath, &$context) {
    
    // OH DARN! i cannot pass parser nad mapper as arguments because of serialization
    // @todo find a better way how use parser and mapper without recreating objects
    $parser = new EntityXMLParser($filePath);
    $mapper = new EntityXMLMapper();

    // Take xml record with selected index
    // Build dependency tree
    // Transform xml to array
    $parser->convertXMLRecord($index);

    // Get dependency tree
    $dependency_tree = $parser->getDependencyTree();

    // Get the result of xml to array transformation
    // Variable now contains array of elements ( dependant entities included ),
    // ! Entities data arrays are collected in array ordered considering dependency needs. IE. taxonomy term is needed
    // by article and article is needed by comment. the order will be ('taxonomy term', 'article', 'comment')
    $entities_data = $parser->getContentArray();

    // We want to store our entities temporary. After creating the entities we want to keep them because of dependency
    $entities = array();

    foreach ($entities_data as $record_id => $entity_data) {
      $entity_data = array_shift($entity_data);
      $entity_name = $entity_data['#attributes']['name'];
      
      // clear dependencies array structure
      $dependencies = array();
      // clear dependencies ids
      $ids = array();
      // get dependency tree for selected record_id
      // we are extracting only the nodes of tree which are needed for this entity - we don't need whole tree
      $dependency_node = EntityXMLParser::getDependencyForEntity($dependency_tree, $record_id);
      // transform structured tree array into simple 1-dimensional array containing only record_id's
      if ($dependency_node) {
        EntityXMLParser::getDependencyIDArray($dependency_node, $ids);
      }


      // Check if any dependencies
      if (count($ids)) {
        foreach ($ids as $id) {
          // Cause the entities are building in order needed we can safely assume that our dependency is already
          // created
          $dependencies[$id] = $entities[$id];
        }
      }

      // Set requirements for mapping needs, this should be already saved entities, with entity id's
      $method = "create";
      if (isset($entity_data['#attributes']['method'])) {
        $method = $entity_data['#attributes']['method'];
      }

      //$existing_entity = EntityXMLMapper::checkExistingEntity($record_id, $filePath);
      switch ($method) {
        case 'update':
          // get all entities that meets the conditions
          $query = $mapper->buildEntityQuery($entity_data);
          $result_set = $query->execute();
          // if there are results (conditions were met)
          if(sizeof($result_set)) {
            $updateEntities = entity_load($entity_name, array_keys($result_set[$entity_name]));
            // fallback to create, no entities matched the conditions
            $mapper->setRequirements($dependencies);

            // repopulate each entity with data form xml and save
            foreach ($updateEntities as $updateEntity) {
              $mapper->buildEntity($entity_data, $filePath, $updateEntity);
              $entities[$record_id] = $mapper->getEntity();
              xml2node_entity_save($entities[$record_id], $filePath, $update = TRUE);
            }
            break;
          }
          // there were no entities to update found, lets go to create.
        case 'create':
          // create entities
          // if entity with corresponding file and record_id already exist, we are skipping
          // @todo: consider saving policy ? aggressive, mild ?
          if (!EntityXMLMapper::checkExistingEntity($record_id, $filePath)) {
            $mapper->setRequirements($dependencies);
            $mapper->buildEntity($entity_data, $filePath);
            $entities[$record_id] = $mapper->getEntity();
            xml2node_entity_save($entities[$record_id], $filePath);
          } else {
            $entities[$record_id] = EntityXMLMapper::checkExistingEntity($record_id, $filePath);
            drupal_set_message(t('Importing entity labeled "!name" with record #ID: !id already imported',
              array('!name' => $entity_data['#attributes']['name'], '!id' => $record_id)), 'status');
          }

          break;
        case 'delete':
          // get all entities that meets the conditions
          $query = $mapper->buildEntityQuery($entity_data);

          $result_set = $query->execute();
          $entity_name = $entity_data['#attributes']['name'];
          $deleteIds = array_keys($result_set[$entity_name]);

          // delete all entities
          foreach ($deleteIds as $id) {
            $record = array(
              'file' => $filePath,
              'rid' => $entity_data->meta['id'],
              'eid' => 0,
              'entity_type' => $entity_data->meta['entity_name'],
              'created' => time(),
            );

            // return value is dependant on entity. We just have to assume there is a proper
            // return value if deleting was successful
            if(entity_delete($entity_name, $id)) {
              watchdog('x2n', t('Entity labeled "!name" with #ID: !id deleted.',
                array('!name' => $entity_name, '!id' => $id)), array('entity_data' => $entity_data));
            }

            drupal_write_record('xml_to_node', $record);
            drupal_set_message(t('Entity labeled "!name" with #ID: !id deleted.',
                               array('!name' => $entity_name, '!id' => $id)));
            
          }
          break;
        default:

          break;
      }
    }
  }
}
