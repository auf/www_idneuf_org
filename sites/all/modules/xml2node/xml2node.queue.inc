<?php
/*
 * @file
 *
 * Function associated with drupal queue
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */

/**
 * Crawls through predefined hotfolders and deletes all obsolete xml files
 * if the queue is empty
 */
function xml2node_delete_obsolete_import_files() {

  $queue = DrupalQueue::get('xml2node_queue');
  $number_of_items = $queue->numberOfItems();
  // TODO: improve this, so that completed files will be deleted, even if the queue ist not empty
  
  if ($number_of_items == 0) {
    // get hotfolder from settings
    $hotfolders = explode("\n", variable_get('xml2node_hotfolders', ''));

    // if there are hotfolders defined, crawl them
    foreach ((array) $hotfolders as $hotfolder) {
      // get the already imported xml-files
      $files_to_delete = file_scan_directory($hotfolder, '/imported$/i');

      // delete the files
      foreach ($files_to_delete as $filepath => $file) {
        file_unmanaged_delete($filepath);
      }
    }
  }
}

/**
 * crawls through predefined hotfolders and returnes all xml files to import
 *
 * @return array paths to xml files
 */
function xml2node_get_files_to_process() {
  $files = array();

  // get hotfolder from settings
  $hotfolders = explode("\n", variable_get('xml2node_hotfolders', ''));

  // if there are hotfolders defined, crawl them
  foreach ((array) $hotfolders as $hotfolder) {
    $hotfolder = trim($hotfolder);

    $files_in_hotfolder = file_scan_directory($hotfolder, "/xml$/i");

    foreach ($files_in_hotfolder as $filepath => $file_infos) {
      $files[] = $filepath;
    }
  }

  return $files;
}