<?php
/**
 * @file
 * CTools Plugins Styles Region Interface.
 */

namespace CTools\Plugins\Styles;

/**
 * Interface StylesRegionInterface.
 *
 * @package CTools\Plugins\Styles
 */
interface StylesRegionInterface extends StylesInterface {

  /**
   * Preprocess variables before passing them to theme engine.
   *
   * @param \panels_display $display
   *   Values from configuration form.
   * @param array $settings
   *   Values from configuration form.
   * @param array $variables
   *   All available variables (including "display" and "settings").
   */
  public static function preprocess(\panels_display $display, array &$settings, array &$variables);

}
