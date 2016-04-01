<?php
/**
 * @file
 * CTools Plugins Styles Pane Interface.
 */

namespace CTools\Plugins\Styles;

/**
 * Interface StylesPaneInterface.
 *
 * @package CTools\Plugins\Styles
 */
interface StylesPaneInterface extends StylesInterface {

  /**
   * Preprocess variables before passing them to theme engine.
   *
   * @param \stdClass $content
   *   Content block.
   * @param array $settings
   *   Values from configuration form.
   * @param array $variables
   *   All available variables (including "settings" and "content").
   */
  public static function preprocess(\stdClass $content, array &$settings, array &$variables);

}
