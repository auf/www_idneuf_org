<?php
/**
 * @file
 * Provide an access restriction based on HTTP status codes, handled by Drupal.
 */

namespace CTools\Plugins\Access;

/**
 * Class HTTPStatusCode.
 *
 * @package CTools\Plugins\Access
 */
class HTTPStatusCode implements AccessInterface {

  /**
   * {@inheritdoc}
   */
  public static function name() {
    return t('HTTP status code');
  }

  /**
   * {@inheritdoc}
   */
  public static function info() {
    return [
      'description' => t('Restrict an access by HTTP status code(s).'),
    ];
  }

  /**
   * {@inheritdoc}
   */
  public static function dependencies() {
    return [];
  }

  /**
   * {@inheritdoc}
   */
  public static function summary(array $conf, \ctools_context $context = NULL) {
    return t('Content available when server responds with the following HTTP codes: @codes', [
      '@codes' => implode(', ', $conf['available_codes']),
    ]);
  }

  /**
   * {@inheritdoc}
   */
  public static function accessible(array $conf, \ctools_context $context = NULL) {
    // The drupal_get_http_header() return something like: "404 Not Found".
    return in_array((int) drupal_get_http_header('Status'), $conf['available_codes']);
  }

  /**
   * {@inheritdoc}
   */
  public static function configurationForm(array &$form, array &$form_state, array &$conf) {
    $form['available_codes'] = [
      '#type' => 'checkboxes',
      '#title' => t('Choose HTTP status code for which accesses available'),
      // HTTP codes, handled by Drupal.
      '#options' => drupal_map_assoc([403, 404, 500, 503]),
    ];
  }

  /**
   * {@inheritdoc}
   */
  public static function configurationFormValidate(array &$form, array &$form_state, array &$values) {

  }

  /**
   * {@inheritdoc}
   */
  public static function configurationFormSubmit(array &$form, array &$form_state, array &$conf) {
    $conf['available_codes'] = array_filter($conf['available_codes']);
  }

  /**
   * {@inheritdoc}
   */
  public static function configurationFormElementCallback(array &$form, array &$form_state, array &$conf, array &$commands, array $element) {

  }

}
