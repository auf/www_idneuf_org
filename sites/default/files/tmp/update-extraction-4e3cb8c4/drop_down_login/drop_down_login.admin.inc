<?php
/**
 * @file
 * Drop down login administration and module settings UI.
 */

/**
 * Callback for drop down login setting form.
 */
function drop_down_login_settings($form, &$form_state) {
  $form['#attached']['css'] = array(drupal_get_path('module', 'drop_down_login') . '/theme/drop_down_login.css');
  $form['drop_down_login_setting']['drop_down_login_want_myaccount'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable My Account drop-down after login.'),
    '#default_value' => variable_get('drop_down_login_want_myaccount'),
    '#description' => t('If you want a drop-down menu to appear with "View Profile"
            and "Logout" (as well as optional links you specify below between these two
            options) instead of just the logout button, check this box.'),
  );

  $form['drop_down_login_myaccount_links'] = array(
    '#type' => 'fieldset',
    '#weight' => 80,
    '#tree' => TRUE,
    '#title' => t('Additional Links'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="js-ajax-elements-wrapper">',
    '#suffix' => '</div>',
    '#description' => t('If you chose to enable the "My Account" drop-down after login,
            you can include additional links by completing the fields below, one set
            for each link.'),
  );

  $drop_down_login_myaccount_links = variable_get('drop_down_login_myaccount_links', array());

  usort($drop_down_login_myaccount_links, function($a, $b) {
    return $a['weight'] - $b['weight'];
  });
  $numb_links = count($drop_down_login_myaccount_links);
  $links_deltas = $numb_links > 0 ? range(0, $numb_links - 1) : array();
  $form_state['field_deltas'] = isset($form_state['field_deltas']) ? $form_state['field_deltas'] : $links_deltas;

  $field_count = $form_state['field_deltas'];

  foreach ($field_count as $delta) {
    $form['drop_down_login_myaccount_links'][$delta] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('container-inline'),
      ),
      '#tree' => TRUE,
    );

    $form['drop_down_login_myaccount_links'][$delta]['weight'] = array(
      '#type'          => 'weight',
      '#title'         => t('Weight'),
      '#default_value' => (!empty($drop_down_login_myaccount_links[$delta])) ? $drop_down_login_myaccount_links[$delta]['weight'] : '',
      '#title-display' => 'invisible',
      // A class is required by drag and drop.
      '#attributes' => array('class' => array('drop-down-login-item-weight')),
    );

    $form['drop_down_login_myaccount_links'][$delta]['menu']['menu_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Menu Name'),
      '#size' => 60,
      '#required' => TRUE,
      '#default_value' => (!empty($drop_down_login_myaccount_links[$delta])) ? $drop_down_login_myaccount_links[$delta]['menu']['menu_name'] : '',
      '#description' => t('The text to be used for this link in the My Account drop down.'),
    );

    $form['drop_down_login_myaccount_links'][$delta]['menu']['menu_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Menu URL'),
      '#size' => 60,
      '#required' => TRUE,
      '#max_length' => 512,
      '#element_validate' => array('drop_down_login_menu_edit_item_validate'),
      '#default_value' => (!empty($drop_down_login_myaccount_links[$delta])) ? $drop_down_login_myaccount_links[$delta]['menu']['menu_url'] : '',
      '#description' => t('The path for this menu link. This can be an internal Drupal path such as node/add or an external URL such as http://drupal.org. Enter :front to link to the front page.', array(':front' => "<front>")),
    );

    $form['drop_down_login_myaccount_links'][$delta]['menu']['remove_name'] = array(
      '#type' => 'submit',
      '#value' => t('- Remove'),
      '#submit' => array('drop_down_login_ajax_add_more_remove',),
      '#limit_validation_errors' => array(),
      // See the examples in ajax_example.module for more details on the
      // properties of #ajax.
      '#ajax' => array(
        'callback' => 'drop_down_login_ajax_add_more_remove_callback',
        'wrapper' => 'js-ajax-elements-wrapper',
      ),
      '#weight' => -50,
      '#attributes' => array(
        'class' => array('button-small',),
      ),
      '#name' => 'remove_name_' . $delta,
    );
  }

  $form['drop_down_login_myaccount_links']['add_name'] = array(
    '#type' => 'submit',
    '#value' => t('Add a link'),
    '#submit' => array('drop_down_login_ajax_add_more_add_one',),
    '#limit_validation_errors' => array(),
    // See the examples in ajax_example.module for more details on the
    // properties of #ajax.
    '#ajax' => array(
      'callback' => 'drop_down_login_ajax_add_more_add_one_callback',
      'wrapper' => 'js-ajax-elements-wrapper',
    ),
    '#weight' => 100,
  );

  $form['drop_down_login_myaccount_links']['#theme'] = 'drop_down_login_dragandrop';

  return system_settings_form($form);
}

/**
 * Validate form values for a menu link being added or edited.
 */
function drop_down_login_menu_edit_item_validate($element, &$form, &$form_state) {
  $item['link_path'] = $element['#value'];
  $normal_path = drupal_get_normal_path($item['link_path']);
  if ($item['link_path'] != $normal_path) {
    drupal_set_message(t('The menu system stores system paths only, but will use the URL alias for display. %link_path has been stored as %normal_path', array('%link_path' => $item['link_path'], '%normal_path' => $normal_path)));
    $item['link_path'] = $normal_path;
  }
  if (!url_is_external($item['link_path'])) {
    $parsed_link = parse_url($item['link_path']);
    if (isset($parsed_link['query'])) {
      $item['options']['query'] = drupal_get_query_array($parsed_link['query']);
    }
    else {
      // Use unset() rather than setting to empty string
      // to avoid redundant serialized data being stored.
      unset($item['options']['query']);
    }
    if (isset($parsed_link['fragment'])) {
      $item['options']['fragment'] = $parsed_link['fragment'];
    }
    else {
      unset($item['options']['fragment']);
    }
    if (isset($parsed_link['path']) && $item['link_path'] != $parsed_link['path']) {
      $item['link_path'] = $parsed_link['path'];
    }
  }

  // Element name construct as required by form_set_error.
  $highlight = implode('][', $element['#parents']);

  if (!trim($item['link_path']) || !drupal_valid_path($item['link_path'], TRUE)) {
    form_set_error($highlight, t("The path '@link_path' is either invalid or you do not have access to it.", array('@link_path' => $item['link_path'])));
  }
}

/**
 * Ajax submit handler for the form to remove added field.
 */
function drop_down_login_ajax_add_more_remove($form, &$form_state) {
  $delta_remove = $form_state['triggering_element']['#parents'][1];
  $k = array_search($delta_remove, $form_state['field_deltas']);
  unset($form_state['field_deltas'][$k]);

  $form_state['rebuild'] = TRUE;
  drupal_get_messages();
}

/**
 * Ajax callback handler for removing added field.
 */
function drop_down_login_ajax_add_more_remove_callback($form, &$form_state) {
  return $form['drop_down_login_myaccount_links'];
}

/**
 * Ajax submit handler for the form to add more field.
 */
function drop_down_login_ajax_add_more_add_one($form, &$form_state) {
  $form_state['field_deltas'][] = count($form_state['field_deltas']) > 0 ? max($form_state['field_deltas']) + 1 : 0;

  $form_state['rebuild'] = TRUE;
  drupal_get_messages();
}

/**
 * Ajax callback handler to add more field.
 */
function drop_down_login_ajax_add_more_add_one_callback($form, $form_state) {
  return $form['drop_down_login_myaccount_links'];
}
