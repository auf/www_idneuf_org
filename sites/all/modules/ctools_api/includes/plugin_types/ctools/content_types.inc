<?php
/**
 * @file
 * API for CTools content types plugins.
 */

/**
 * {@inheritdoc}
 *
 * @see \CTools\PluginConstructor::callTypeConstructor()
 */
function ctools_api_content_types(array &$information, array $interfaces) {
  if (!isset($information['category'])) {
    $information['category'] = CTOOLS_API_MODULE_TITLE;
  }
}

/**
 * {@inheritdoc}
 *
 * @see ctools_content_admin_title()
 */
function ctools_api_ctools_api_content_type_admin_title($object, array $conf) {
  /* @var \CTools\Plugins\ContentTypes\ContentTypesInterface $object */
  if (class_exists($object)) {
    $variants = $object::themeVariants();

    return $object::name() . ' (' . (isset($variants[$conf['theme']]) ? $variants[$conf['theme']] : t('Default')) . ')';
  }

  return t('The plugin object @object does not exist.', [
    '@object' => $object,
  ]);
}

/**
 * {@inheritdoc}
 *
 * @see ctools_content_admin_info()
 */
function ctools_api_ctools_api_content_type_admin_info($content_type, array $conf, array $context) {
  return call_user_func_array('ctools_api_ctools_api_content_type_render', func_get_args());
}

/**
 * {@inheritdoc}
 *
 * @see ctools_content_render()
 */
function ctools_api_ctools_api_content_type_render($content_type, array $conf, array $args, \ctools_context $context = NULL) {
  $plugin = ctools_content_get_subtype('ctools_api', $content_type);
  $block = new \stdClass();

  $block->title = $conf['override_title_text'];
  $block->delta = $content_type;
  $block->region = $block->module = 'ctools_api';
  $block->content = '';

  if (!empty($plugin) && class_exists($plugin['object'])) {
    $plugin['object']::preprocess($conf, $args, $context);

    $block->content = ctools_api_apply_theme($content_type, $conf, $plugin, [
      'content' => $conf,
    ]);
  }

  return $block;
}

/**
 * {@inheritdoc}
 *
 * @see ctools_content_form()
 */
function ctools_api_ctools_api_content_type_edit_form(array $form, array &$form_state) {
  ctools_api_plugin_base_configuration_form($form, $form_state);

  if (isset($form['override_title'])) {
    // Enable title overriding by default and hide the checkbox.
    $form['override_title']['#default_value'] = TRUE;
    $form['override_title']['#access'] = FALSE;

    // Make-up field for pane title.
    $form['override_title_text'] = array_merge($form['override_title_text'], [
      '#title' => t('Pane title'),
      '#attributes' => [
        'placeholder' => t('Title'),
      ],
    ]);
  }

  return $form;
}
