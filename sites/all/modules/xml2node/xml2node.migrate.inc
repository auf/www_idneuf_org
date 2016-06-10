<?php

/*
 * @file
 *
 *  @author Jan Azzati - Previon AG
 *  @author blueminds.eu
 */

/**
 * Form for processing the import
 * 
 * @param $form
 * @param $form_state
 * @return array
 */
function xml2node_migrate_form($form, &$form_state) {
  $form = array();
  $form['#attached'] = array(
    'css' => array(drupal_get_path('module', 'xml2node') . '/css/xml2node.css'),
    'js' => array(drupal_get_path('module', 'xml2node') . '/js/xml2node.js'),
  );
  
  // field for the filepath
  $form['file'] = array(
    '#type' => 'textfield',
    '#title' => t('XML File'),
    '#default_value' => isset($_GET['file']) ? $_GET['file'] : variable_get('xml2node_filepath', 'sites/default/files/'),
    '#size' => 60,
    '#maxlength' => 250,
    '#description' => t('The path to the XML File you would like to import. You can import same file multiple times.
      Only new records will be imported. If the import fails, system will remember which entities were already imported
      and wont import them again.'),
    '#required' => TRUE,
  );

  $form['actions'] = array(
    '#type' => 'fieldset',
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );

  $form['actions']['check'] = array(
    '#type' => 'submit',
    '#value' => t('Check'),
    '#validate' => array('xml2node_migrate_form_validate'),
    '#submit' => array('xml2node_migrate_form_report_submit'),
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
    '#validate' => array('xml2node_migrate_form_validate'),
    '#submit' => array('xml2node_migrate_form_submit'),
  );

  return $form;
}

/**
 * Validation callback for xml2node_migrate_form
 * 
 * @param $form
 * @param $form_state
 * @return void
 */
function xml2node_migrate_form_validate($form, &$form_state) {
  $data = $form_state['values'];

  // check if specified path points to existing file
  if (!is_dir($data['file'])) {
    if (!file_exists($data['file'])) {
      form_set_error('file', t('There is no file.'));
    }
  }
  else {
    form_set_error('file', t('Specified path leads to directory.'));
  }
}


/**
 * Submit callback for xml2node_migrate_form
 * 
 * @param $form
 * @param $form_state
 * @return void
 */
function xml2node_migrate_form_submit($form, &$form_state) {
  $data = $form_state['values'];

  // save the field values into variables, so they are present the next time the form is called
  variable_set('xml2node_filepath', $data['file']);

  // proceed the node import from the xml file
  xml2node_proceed_import($data['file']);
}

/**
 * Display file report
 * 
 * @param $form
 * @param $form_state
 * @return void
 */
function xml2node_migrate_form_report_submit($form, &$form_state) {
  global $base_url;
  $data = $form_state['values'];
  $form_state['redirect'] = url($base_url . '/admin/structure/xml2node/import', array('query' => array('file' => $data['file'])));
}


/**
 * @param $form
 * @param $form_state
 * @param $file
 * @return array
 */
function xml2node_form_file_report($form, &$form_state, $file) {
  $form = array();
  $parser = new EntityXMLParser($file);
  
  $entities = $parser->getAllXMLRecords();
  $imported_ids = db_select('xml_to_node', 'xtn')
    ->condition('file', $file)
    ->fields('xtn', array('rid'))
    ->execute()->fetchCol();

  foreach ($entities as $record_id => $entity) {
    $entity = array_shift($entity);
    $record_id = $entity['#attributes']['id'];
    
    $imported = FALSE;
    if(array_search($record_id, $imported_ids) !== FALSE) {
      $imported = TRUE;
    }

    $entity_data[$record_id] = array(
      'imported' =>  $imported,
      'id' => $entity['#attributes']['id'],
      'name' => $entity['#attributes']['name'],
      'type' => $entity['#attributes']['type'],
      'method' => isset($entity['#attributes']['method']) ? $entity['#attributes']['method'] : 'create'
    );

    $checkbox_data[$record_id] = '';
  }

  $form['entity_data'] = array(
    '#type' => 'value',
    '#value' => $entity_data,
  );

  $form['file'] = array(
    '#type' => 'value',
    '#value' => $file,
  );

  $form['checkbox'] = array(
    '#type' => 'checkboxes',
    '#options' => $checkbox_data,
  );
  
  $form['select'] = array(
    '#type' => 'button',
    '#value' => t('Select all'),
    '#attributes' => array('class' => array('form-xml2node-submit')),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import selected'),
    '#submit' => array('xml2node_form_file_report_submit'),
  );

  return $form;
}

function xml2node_form_file_report_submit($form, &$form_state) {
  global $base_url;
  
  $indexes = array();
  $data = $form_state['values'];
  
  array_unique($data['checkbox']);
  foreach($data['checkbox'] as $value) {
    if(!empty($value)) {
      $indexes[] = $value;
    }
  }
  
  // proceed the node import from the xml file
  if(count($indexes)) {
    xml2node_proceed_import($data['file'], XML2NODE_METHOD_BATCH, $indexes);
  }

  $form_state['redirect'] = url($base_url . '/admin/structure/xml2node/import', array('query' => array('file' => $data['filepath'])));
}


