<?php

/*
 * @file
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */

function xml2node_page_import() {
  $output = '';

  $migrate_form = drupal_get_form('xml2node_migrate_form');
  $output .= drupal_render($migrate_form);
  if(isset($_GET['file'])) {
    $file_report = drupal_get_form('xml2node_form_file_report', $_GET['file']);
    $output .= drupal_render($file_report);
  }

  return $output;
}
 
