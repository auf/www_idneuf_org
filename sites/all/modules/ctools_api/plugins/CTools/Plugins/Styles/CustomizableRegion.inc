<?php
/**
 * @file
 * Customize region markup and attributes.
 */

namespace CTools\Plugins\Styles;

/**
 * Class CustomizableRegion.
 *
 * @package CTools\Plugins\Styles
 */
class CustomizableRegion extends Customizable implements StylesRegionInterface {

  /**
   * {@inheritdoc}
   */
  public static function name() {
    return t('Customizable region');
  }

  /**
   * {@inheritdoc}
   */
  public static function preprocess(\panels_display $display, array &$settings, array &$variables) {
    self::processSettings([], $settings);
  }

  /**
   * {@inheritdoc}
   */
  public static function configurationForm(array &$form, array &$form_state, array &$conf) {
    self::formItem([], $form, $form_state, $conf, [
      'div',
      'main',
      'footer',
      'header',
      'section',
    ]);
  }

}
