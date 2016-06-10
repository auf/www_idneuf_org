<?php
/*
 * @file
 *
 * Settings forms
 *
 * @author Jan Azzati - Previon AG
 * @author blueminds.eu
 */

/**
 * Xml2node settings form
 * @return array
 */
function xml2node_settings_form() {
  $form = array();

  $form['xml2node_run_on_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Import Nodes on cron'),
    '#default_value' => variable_get('xml2node_run_on_cron', 0),
    '#description' => t('Import Nodes from XML Files stored in Hotfolders on every cron run?'),
  );

  $form['drupal_queue_on_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Process queue on drupal cron'),
    '#default_value' => variable_get('drupal_queue_on_cron', 0),
    '#description' => t('Should the drupal queue module process queues on normal cron?'),
  );
  
  $form['xml2node_queue_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Queue worker time'),
    '#default_value' => variable_get('xml2node_queue_time', 15),
    '#size' => 4,
    '#maxlength' => 4,
    '#description' => t('How much time Drupal should spend on calling the queue worker in seconds.'),
  );

  $form['xml2node_hotfolders'] = array(
    '#type' => 'textarea',
    '#title' => t('Hotfolders'),
    '#default_value' => variable_get('xml2node_hotfolders', ''),
    '#rows' => 4,
    '#description' => t('Add Hotfolders to be crawled on cron (each line, one path relative to the base path)'),
  );
  
  return system_settings_form($form);
}

/**
 * Page callback for displaying queue stats
 * @return string
 */
function xml2node_show_queue_status() {
  
  $queue = DrupalQueue::get('xml2node_queue');
  return format_plural($queue->numberOfItems(), 'There is currently 1 item in the queue!', 'There are currently @count items in the queue!');
}