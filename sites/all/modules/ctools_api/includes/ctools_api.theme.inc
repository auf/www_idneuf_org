<?php
/**
 * @file
 * Alterations of theme.
 */

/**
 * Override of theme_panels_flexible().
 *
 * @internal
 *
 * @see theme_panels_flexible()
 *
 * @param array $variables
 *   An array of variables to preprocess.
 *
 * @return string
 *   HTML markup.
 */
function ctools_api_panels_flexible(array $variables) {
  panels_flexible_convert_settings($variables['settings'], $variables['layout']);

  return _ctools_api_panels_flexible_render_items(
    panels_flexible_create_renderer(
      FALSE,
      $variables['css_id'],
      $variables['content'],
      $variables['settings'],
      $variables['display'],
      $variables['layout'],
      $variables['renderer']
    ),
    $variables['settings']['items']['canvas']['children']
  );
}

/**
 * Render a piece of a flexible layout.
 *
 * @internal
 *
 * @see panels_flexible_render_items()
 *
 * @param \stdClass $renderer
 *   Layout configuration.
 * @param array $regions
 *   Layout regions and their content.
 *
 * @return string
 *   HTML markup.
 */
function _ctools_api_panels_flexible_render_items(\stdClass $renderer, array $regions) {
  $groups = [
    'left' => '',
    'right' => '',
    'middle' => '',
  ];

  foreach ($regions as $id) {
    $item = $renderer->settings['items'][$id];
    $hide_empty = empty($renderer->settings['items'][$id]['hide_empty']);
    $content = '';

    switch ($item['type']) {
      case 'column':
      case 'row':
        $content = trim(call_user_func(__FUNCTION__, $renderer, $item['children']));
        break;

      case 'region':
        $content = isset($renderer->content[$id]) ? trim($renderer->content[$id]) : '';
        break;
    }

    if ($hide_empty || !empty($content)) {
      $groups[isset($renderer->positions[$id]) ? $renderer->positions[$id] : 'middle'] .= _ctools_api_panels_flexible_render_item($renderer, $item, $content, $id);
    }
  }

  return implode(array_filter($groups));
}

/**
 * {@inheritdoc}
 *
 * @internal
 *
 * @see panels_flexible_render_item()
 */
function _ctools_api_panels_flexible_render_item(\stdClass $renderer, array $item, $content, $id) {
  $output = '';

  if (!empty($renderer->admin)) {
    $output .= panels_flexible_render_item_links($renderer, $id, $item);
  }

  $output .= $content;

  return $output;
}
