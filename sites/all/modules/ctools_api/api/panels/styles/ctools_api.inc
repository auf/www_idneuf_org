<?php
/**
 * @file
 * Collect all Panels plugins of "Styles" type.
 */

/**
 * Implements <MODULE>_<FILENAME>_panels_styles().
 */
function ctools_api_ctools_api_panels_styles(array $info) {
  return ctools_api_type_definition_get($info['type']) + [
    'title' => t('@module Style', [
      '@module' => CTOOLS_API_MODULE_TITLE,
    ]),
  ];
}
