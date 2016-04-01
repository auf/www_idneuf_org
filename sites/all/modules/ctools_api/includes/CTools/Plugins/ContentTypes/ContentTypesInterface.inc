<?php
/**
 * @file
 * CTools Plugins Content Types Interface.
 */

namespace CTools\Plugins\ContentTypes;

use CTools\Plugins\TemplatablePluginInterface;
use CTools\Plugins\ConfigurablePluginInterface;

/**
 * Interface ContentTypesInterface.
 *
 * @package CTools\Plugins\ContentTypes
 */
interface ContentTypesInterface extends TemplatablePluginInterface, ConfigurablePluginInterface {

  /**
   * Preprocess variables before passing them to theme engine.
   *
   * @param array $variables
   *   Values from configuration form.
   * @param array $arguments
   *   Content type arguments.
   * @param \ctools_context $context
   *   Content type context.
   */
  public static function preprocess(array &$variables, array &$arguments, \ctools_context $context = NULL);

}
