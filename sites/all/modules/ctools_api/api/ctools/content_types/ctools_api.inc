<?php
/**
 * @file
 * Collect all CTools plugins of "ContentTypes" type.
 */

/**
 * Implements <MODULE>_<FILENAME>_ctools_content_types().
 *
 * NOTE! This type of plugins cannot be implemented in unified
 * way as, for example, "styles", because child plugins does not
 * allowed in type definition.
 *
 * @see ctools_plugin_load_includes()
 * @see ctools_plugin_process()
 */
function ctools_api_ctools_api_ctools_content_types(array $info) {
  return [
    'title' => t('@module Content', [
      '@module' => CTOOLS_API_MODULE_TITLE,
    ]),
    'category' => CTOOLS_API_MODULE_TITLE,
    'content types' => ctools_api_get_plugins($info['type']),
  ];
}
