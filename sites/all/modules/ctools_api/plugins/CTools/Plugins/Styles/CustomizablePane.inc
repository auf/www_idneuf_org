<?php
/**
 * @file
 * Customize pane markup and attributes.
 */

namespace CTools\Plugins\Styles;

/**
 * Class CustomizablePane.
 *
 * @package CTools\Plugins\Styles
 */
class CustomizablePane extends Customizable implements StylesPaneInterface {

  /**
   * {@inheritdoc}
   */
  public static function name() {
    return t('Customizable pane');
  }

  /**
   * {@inheritdoc}
   */
  public static function preprocess(\stdClass $content, array &$settings, array &$variables) {
    foreach (['wrapper', 'title', 'content'] as $name) {
      self::processSettings(['info', $name], $settings);
    }

    $wrapper = array_shift($settings['info']);

    $content->tag = $wrapper['tag'];
    $content->attributes = array_merge_recursive($content->attributes, $wrapper['attributes']);

    unset($content->attributes['tag']);
  }

  /**
   * {@inheritdoc}
   */
  public static function configurationForm(array &$form, array &$form_state, array &$conf) {
    $content_tags = [
      'section',
      'article',
      'div',
    ];

    $form['info'] = [];

    $form['info']['wrapper'] = [
      '#type' => 'horizontal_tab',
      '#title' => t('Wrapper'),
      '#tags' => $content_tags,
    ];

    $form['info']['title'] = [
      '#type' => 'horizontal_tab',
      '#title' => t('Title'),
      '#tags' => [
        'p',
        'a',
        'h1',
        'h2',
        'h3',
        'h4',
        'h5',
        'h6',
        'div',
        'span',
      ],
    ];

    $form['info']['content'] = [
      '#type' => 'horizontal_tab',
      '#title' => t('Content'),
      '#tags' => $content_tags,
    ];

    foreach ($form['info'] as $name => $element) {
      self::formItem(['info', $name], $form, $form_state, $conf, $element['#tags']);
    }

    $form['info']['#type'] = 'horizontal_tabs';
  }

}
