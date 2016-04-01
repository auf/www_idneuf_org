<?php
/**
 * @file
 * API for CTools access plugins.
 */

/**
 * {@inheritdoc}
 *
 * @see \CTools\PluginConstructor::callTypeConstructor()
 */
function ctools_api_access(array &$information, array $interfaces) {
  foreach (['summary', 'callback', 'settings form', 'settings form submit'] as $property) {
    $information[$property] = __FUNCTION__ . '_base_' . str_replace(' ', '_', $property);
  }
}

/**
 * {@inheritdoc}
 *
 * @see ctools_access_summary()
 */
function ctools_api_access_base_summary($conf, $context, array $plugin, $callback = 'summary') {
  if (empty($conf)) {
    $conf = [];
  }

  if (empty($context)) {
    $context = NULL;
  }

  return $plugin['object']::$callback($conf, $context);
}

/**
 * {@inheritdoc}
 *
 * @see ctools_access()
 */
function ctools_api_access_base_callback($conf, $context, array $plugin) {
  return ctools_api_access_base_summary($conf, $context, $plugin, 'accessible');
}

/**
 * {@inheritdoc}
 *
 * @see ctools_access_ajax_edit_item()
 */
function ctools_api_access_base_settings_form(array $form, array &$form_state, $conf) {
  $form_state['conf'] = (array) $conf;
  $items = [];

  ctools_api_plugin_base_configuration_form($items, $form_state);

  $form['settings'] += $items;

  return $form;
}

/**
 * {@inheritdoc}
 *
 * @see ctools_access_ajax_edit_item_submit()
 */
function ctools_api_access_base_settings_form_submit(array $form, array &$form_state) {
  $conf = [];

  // Ternary operator could not be used because only values could
  // be passed by reference.
  if (isset($form_state['values']['settings'])) {
    $conf =& $form_state['values']['settings'];
  }

  $form_state['plugin']['object']::configurationFormSubmit($form, $form_state, $conf);
}
