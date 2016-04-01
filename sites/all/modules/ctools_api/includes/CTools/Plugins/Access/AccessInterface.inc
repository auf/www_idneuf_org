<?php
/**
 * @file
 * CTools Plugins Access Interface.
 */

namespace CTools\Plugins\Access;

use CTools\Plugins\ConfigurablePluginInterface;

/**
 * Interface AccessInterface.
 *
 * @package CTools\Plugins\Access
 */
interface AccessInterface extends ConfigurablePluginInterface {

  /**
   * Provide summary depending on settings.
   *
   * @param array $conf
   *   Values from configuration form.
   * @param \ctools_context $context
   *   Access context.
   *
   * @return string
   *   Summary information.
   */
  public static function summary(array $conf, \ctools_context $context = NULL);

  /**
   * Check that access granted.
   *
   * @param array $conf
   *   Values from configuration form.
   * @param \ctools_context $context
   *   Access context.
   *
   * @return bool
   *   TRUE - access granted, FALSE - not.
   */
  public static function accessible(array $conf, \ctools_context $context = NULL);

}
