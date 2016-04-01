<?php
/**
 * @file
 * CTools Plugins Content Types Collection Element.
 */

namespace CTools\Form\Elements;

/**
 * Class Collection.
 *
 * @package CTools\Form\Elements
 */
class Collection {

  const TYPE = 'collection';

  /**
   * Button names. Texts can be changed before creation.
   *
   * @var string[]
   */
  public static $buttonTexts = [
    'remove' => 'Remove',
    'add' => 'Add new item',
  ];

  /**
   * Helper for creating a fields collection.
   *
   * @param string[] $parents
   *   Nesting names.
   * @param array $form
   *   Form elements implementation.
   * @param array $form_state
   *   Drupal form state.
   * @param array $conf
   *   Values from configuration form.
   * @param callable $process
   *   Callback for processing each item in a collection.
   */
  public function __construct(array $parents, array &$form, array &$form_state, array &$conf, callable $process) {
    // Pass button texts to translate interface.
    static::$buttonTexts = array_map('t', static::$buttonTexts);
    $name = ctools_api_html_name_from_array($parents);
    // Check that we already have saved values for our collection.
    $values = drupal_array_get_nested_value($conf, $parents);
    $element = [
      '#tree' => TRUE,
      '#type' => 'table',
      '#sticky' => FALSE,
      '#header' => [],
      '#subtype' => self::TYPE,
      '#attributes' => [
        'class' => ['form-item', self::TYPE],
      ],
    ];

    // If it's a new collection, then init it with a single, empty, value.
    if (NULL === $values) {
      $values = [[]];
    }

    // Walk through the collection items.
    foreach ($values as $i => $value) {
      $items = $process($i, $value);
      $children = element_children($items);

      if (empty($children)) {
        throw new \RuntimeException(t('Callback for collection must return an associative array of form items.'));
      }

      // Populate properties.
      foreach (element_properties($items) as $prop) {
        if (isset($element[$prop]) && is_array($element[$prop])) {
          $element[$prop] = array_merge($element[$prop], $items[$prop]);
        }
        else {
          $element[$prop] = $items[$prop];
        }
      }

      if ('table' === $element['#type']) {
        // Remove titles from elements and set them to table cells.
        foreach ($children as $td) {
          // Extend an item with an #access property. If it absent - Drupal
          // thinks that an access granted. So, this done to not check for
          // FALSE and isset().
          $items[$td] += ['#access' => TRUE];

          // Do not add header if an access was not granted to an element.
          if (!empty($items[$td]['#access'])) {
            $element['#header'][$td] = isset($items[$td]['#title']) ? $items[$td]['#title'] : '';
          }

          unset($items[$td]['#title']);
        }

        // Add the "Remove" button to each row.
        $element['#header']['_operations'] = t('Operations');
      }

      // Could be "fieldset" or "table".
      $element['#attributes']['class'][] = $element['#type'] . '-collection';

      $items['_operations'] = [
        '#type' => 'items',
        '#cell' => [
          'class' => ['operations'],
        ],
      ];

      $items['_operations']['_remove'] = [
        '#ajax' => TRUE,
        // This value MUST BE UNIQUE for every row. Otherwise we always will
        // have the button from last row in $form_state['triggering_element'].
        '#name' => $name . "[$i]",
        '#type' => 'button',
        '#value' => static::$buttonTexts['remove'],
        '#operation' => 'remove',
        '#limit_validation_errors' => [],
      ];

      $element[] = $items;
    }

    $element['_last']['_add'] = [
      '#ajax' => TRUE,
      '#name' => $name,
      '#type' => 'button',
      '#value' => static::$buttonTexts['add'],
      '#operation' => 'add',
      '#limit_validation_errors' => [],
      '#cell' => [
        'colspan' => count($element['#header']),
      ],
    ];

    // Attach a collection, that was generated, to our form.
    drupal_array_set_nested_value($form, $parents, $element);
    // Update form values to able to add new elements to collection.
    drupal_array_set_nested_value($conf, $parents, $values);
  }

}
