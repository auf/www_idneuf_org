<?php
/**
 * @file
 * Entity Reference CTools content type.
 */

namespace CTools\Plugins\ContentTypes;

use CTools\Form\Elements;

/**
 * Class EntityReference.
 *
 * @package CTools\Plugins\ContentTypes
 */
class EntityReference implements ContentTypesInterface {

  /**
   * {@inheritdoc}
   */
  public static function name() {
    return t('Entity Reference');
  }

  /**
   * {@inheritdoc}
   */
  public static function info() {
    return [
      'required context' => new \ctools_context_optional(t('Context'), 'any'),
    ];
  }

  /**
   * {@inheritdoc}
   */
  public static function themeVariants() {
    return [];
  }

  /**
   * {@inheritdoc}
   */
  public static function dependencies() {
    return ['entityreference_autocomplete'];
  }

  /**
   * {@inheritdoc}
   */
  public static function preprocess(array &$variables, array &$arguments, \ctools_context $context = NULL) {

  }

  /**
   * {@inheritdoc}
   */
  public static function configurationForm(array &$form, array &$form_state, array &$conf) {
    if (isset($form_state['contexts'][$conf['context']])) {
      $context = $form_state['contexts'][$conf['context']];

      foreach ($conf['references'] as &$item) {
        $item['entity_type'] = $context->keyword;
      }
    }

    self::entityReferenceCollection(['references'], $form, $form_state, $conf);
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

  }

  /**
   * {@inheritdoc}
   */
  public static function configurationFormElementCallback(array &$form, array &$form_state, array &$conf, array &$commands, array $element) {
    // Process only when AJAX occurred on element from "references".
    if ('references' === reset($element['#parents'])) {
      // Remove field name from parents to be able obtain full row.
      $item =& drupal_array_get_nested_value($form, array_slice($element['#parents'], 0, -1));

      if (isset($item['reference'])) {
        // When type is changed - hide an input with reference to an entity.
        if ('bundles' !== end($element['#parents'])) {
          $item['reference']['#access'] = FALSE;
        }

        // When entity type or bundles are changed - remove referenced value.
        unset($item['reference']['#value']);
      }
    }
  }

  /**
   * Create a collection of entity references.
   *
   * {@inheritdoc}
   *
   * @see \CTools\Form\Elements\Collection
   */
  protected static function entityReferenceCollection(array $parents, array &$form, array &$form_state, array $conf) {
    self::initFormState($form_state);

    new Elements\Collection($parents, $form, $form_state, $conf, function ($i, $data) use ($form_state) {
      return self::referenceItem($form_state, $data);
    });
  }

  /**
   * Create single entity reference element.
   *
   * {@inheritdoc}
   *
   * @see \CTools\Form\Elements\Collection
   */
  protected static function entityReferenceElement(array $parents, array &$form, array &$form_state, array $conf) {
    self::initFormState($form_state);

    $item = ['#tree' => TRUE];
    $item += self::referenceItem($form_state, drupal_array_get_nested_value($conf, $parents) ?: $conf);

    drupal_array_set_nested_value($form, $parents, $item);
  }

  /**
   * Store entity types and information in form state.
   *
   * @param array $form_state
   *   Drupal form state.
   */
  private static function initFormState(array &$form_state) {
    if (empty($form_state['entity_info'])) {
      $form_state['entity_info'] = entity_get_info();
    }

    if (empty($form_state['entity_types'])) {
      $form_state['entity_types'] = [];

      foreach ($form_state['entity_info'] as $type => $info) {
        $form_state['entity_types'][$type] = $info['label'];
      }
    }
  }

  /**
   * {@inheritdoc}
   */
  protected static function referenceItem(array $form_state, array $data) {
    $item = [];

    $item['entity_type'] = [
      '#ajax' => TRUE,
      '#type' => 'select',
      '#title' => t('Entity'),
      '#options' => $form_state['entity_types'],
      '#empty_option' => t('- None -'),
    ];

    $item['bundles'] = [
      '#ajax' => TRUE,
      '#type' => 'select',
      '#title' => t('Bundles'),
      '#access' => FALSE,
      '#multiple' => TRUE,
    ];

    $item['reference'] = [
      '#type' => 'entityreference',
      '#title' => t('Item'),
      '#access' => FALSE,
    ];

    if (!empty($data['entity_type'])) {
      $bundles = [];

      foreach ($form_state['entity_info'][$data['entity_type']]['bundles'] as $bundle => $info) {
        $bundles[$bundle] = $info['label'];
      }

      $item['bundles'] = array_merge($item['bundles'], [
        '#access' => TRUE,
        '#options' => $bundles,
      ]);
    }

    if (!empty($data['bundles'])) {
      $item['reference'] = array_merge($item['reference'], [
        '#access' => TRUE,
        '#era_bundles' => $data['bundles'],
        '#era_entity_type' => $data['entity_type'],
      ]);
    }

    return $item;
  }

}
