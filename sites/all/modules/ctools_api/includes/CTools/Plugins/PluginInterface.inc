<?php
/**
 * @file
 * CTools Plugin Interface.
 */

namespace CTools\Plugins;

/**
 * Interface PluginInterface.
 *
 * @package CTools\Plugins
 * @access private
 */
interface PluginInterface {

  /**
   * Get plugin name.
   *
   * @return string
   *   Human-readable name.
   */
  public static function name();

  /**
   * Additional plugin information. Could be empty.
   *
   * @return string[]
   *   For "content_types":
   *   - 'category' => <string>,
   *   - 'top level' => <bool>,
   *   - 'required context' => <\ctools_context|\ctools_context[]>,
   *   For "access":
   *   - 'description' => <string>,
   *   - 'required context' => <\ctools_context|\ctools_context[]>,
   */
  public static function info();

  /**
   * Plugin dependencies (Drupal modules).
   *
   * @return string[]
   *   Module machine names.
   */
  public static function dependencies();

}
