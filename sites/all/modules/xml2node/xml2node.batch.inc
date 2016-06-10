<?php

/*
 * @file
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */

/**
 * callback for the batch job when its finished
 * 
 * @param $success
 * @param $results
 * @param $operations
 */
function xml2node_import_node_finished($success, $results, $operations) {

  if (!$success) {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message);
  }
  
}