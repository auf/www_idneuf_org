<?php
/**
 * @file
 * Collect all CTools plugins of "Access" type.
 */

/**
 * Implements <MODULE>_<FILENAME>_ctools_access().
 */
function ctools_api_ctools_api_ctools_access(array $info) {
  return ctools_api_type_definition_get($info['type']) + [
    'title' => t('@module Access', [
      '@module' => CTOOLS_API_MODULE_TITLE,
    ]),
  ];
}
