<?php
/**
 * @file
 * Auxiliary functionality.
 */

/**
 * Collect autoloading maps.
 *
 * @return array[]
 *   An array of arrays, keyed by base of the namespace.
 */
function ctools_api_autoloading_paths() {
  $map =& drupal_static(__FUNCTION__, []);

  if (empty($map)) {
    foreach (system_list('module_enabled') as $module_name => $data) {
      if (!empty($data->info['autoload'])) {
        $module_path = dirname($data->filename);

        foreach ($data->info['autoload'] as $subdirectory => $bases) {
          $path = $module_path;

          if (!empty($subdirectory)) {
            $path .= "/$subdirectory";
          }

          foreach ($bases as $base) {
            $map[$base][$path] = [
              'name' => $module_name,
              'path' => $module_path,
            ];
          }
        }
      }
    }
  }

  return $map;
}

/**
 * Scan modules for CTools API plugins.
 *
 * @return \stdClass[]
 *   Plugins that were found.
 */
function ctools_api_search_plugins() {
  $cache = cache_get(__FUNCTION__);
  $plugins = [];

  if (FALSE === $cache || empty($cache->data)) {
    foreach (ctools_api_autoloading_paths() as $base => $modules) {
      foreach ($modules as $path => $module) {
        foreach (file_scan_directory($path, '/\.inc$/') as $file) {
          $class = str_replace('/', '\\', trim(str_replace([$path, '.inc'], '', $file->uri), '/'));

          if (!isset($plugins[$class]) && class_exists($class)) {
            $interfaces = class_implements($class);

            if (isset($interfaces['CTools\Plugins\PluginInterface'])) {
              $reflection = new \ReflectionClass($class);

              if ($reflection->isInstantiable()) {
                $file->sources = $path;
                $file->abstract = $reflection->isAbstract();
                $file->implements = $interfaces;
                $file->module_name = $module['name'];
                $file->module_path = $module['path'];

                $plugins[$class] = $file;
              }
            }
          }
        }
      }
    }

    cache_set(__FUNCTION__, $plugins);
  }
  else {
    $plugins = $cache->data;
  }

  return $plugins;
}

/**
 * Get CTools API plugins.
 *
 * @param string $plugin_type
 *   CTools plugin type.
 *
 * @return array[]
 *   Plugin definitions.
 */
function ctools_api_get_plugins($plugin_type) {
  $cache = cache_get(__FUNCTION__);
  $plugins = [];

  if (FALSE === $cache || empty($cache->data[$plugin_type])) {
    // Transform "content_types" to "ContentTypes", for example.
    $type = ucfirst(ctools_api_to_camel_case($plugin_type));

    foreach (ctools_api_search_plugins() as $class => $plugin) {
      if (isset($plugin->implements[implode('\\', ['CTools', 'Plugins', $type, $type . 'Interface'])])) {
        try {
          $plugins[$class] = array_merge((new \CTools\PluginConstructor($class, $plugin->implements, $plugin_type))->getInfo(), [
            'name' => "ctools_api:$class",
            'path' => dirname($plugin->uri),
            'file' => $plugin->filename,
            'object' => $class,
            'sources' => $plugin->sources,
            'location' => $plugin->uri,
            'plugin type' => $plugin_type,
            'plugin module' => $plugin->module_name,
            'plugin module path' => $plugin->module_path,
          ]);
        }
        catch (\Exception $e) {
          watchdog_exception(CTOOLS_API_MODULE_TITLE, $e);
        }
      }
    }

    cache_set(__FUNCTION__, [$plugin_type => $plugins]);
  }
  else {
    $plugins = $cache->data[$plugin_type];
  }

  return $plugins;
}

/**
 * Extend CTools plugin definition to provide child plugins.
 *
 * @see ctools_plugin_load_includes()
 * @see ctools_plugin_process()
 *
 * @param string $type
 *   Original plugin type (e.g. "access", "styles", "content_types");
 *
 * @return array
 *   ['children'] - all children plugin definitions;
 *   ['get children'] - callback for return all children;
 *   ['get child'] - callback for return selected child.
 */
function ctools_api_type_definition_get($type) {
  return [
    // Custom key. Store all styles to not call this function twice.
    'children' => ctools_api_get_plugins($type),
    // Should return collection of children styles.
    'get children' => __FUNCTION__ . '_children',
    // Should return single definition from the children collection.
    'get child' => __FUNCTION__ . '_child',
  ];
}

/**
 * Collect all child plugins.
 *
 * @internal
 *
 * @see ctools_get_plugins()
 *
 * @param array $plugin
 *   Plugin definition information.
 * @param string $parent
 *   Machine name of the origin plugin (ctools_api).
 *
 * @return array[]
 *   Style plugin definitions.
 */
function ctools_api_type_definition_get_children(array $plugin, $parent) {
  foreach ($plugin['children'] as $name => $info) {
    // Rename keys in array according to CTools documentation.
    $plugin['children']["$parent:$name"] = $info;
    unset($plugin['children'][$name]);
  }

  return $plugin['children'];
}

/**
 * Chose single plugin from children.
 *
 * @internal
 *
 * @param array $plugin
 *   Plugin definition information.
 * @param string $parent
 *   Machine name of the origin plugin (ctools_api).
 * @param string $child
 *   Machine name of the child plugin.
 *
 * @return array
 *   Style plugin definition.
 */
function ctools_api_type_definition_get_child(array $plugin, $parent, $child) {
  return $plugin['children'][$child];
}

/**
 * Convert string to "camelCase" format.
 *
 * @param string $argument
 *   Input string.
 *
 * @return string
 *   Transformed string.
 */
function ctools_api_to_camel_case($argument) {
  return lcfirst(implode(array_map('ucfirst', explode('_', $argument))));
}

/**
 * Convert string to "underscore" format.
 *
 * @param string $argument
 *   Input string.
 *
 * @return string
 *   Transformed string.
 */
function ctools_api_to_underscore($argument) {
  return strtolower(preg_replace('/(?<=\w)(?=[A-Z])/', '_$1', $argument));
}

/**
 * Replace all "_" and ":" by "-".
 *
 * @example
 * TestTest:test_test => test-test-test-test
 *
 * @param string $argument
 *   Input string.
 *
 * @return string
 *   Transformed string.
 */
function ctools_api_to_dashes($argument) {
  return str_replace(['_', ':'], '-', ctools_api_to_underscore($argument));
}

/**
 * Generate "name" HTML attribute for form fields.
 *
 * @param string[] $parents
 *   Element parents.
 *
 * @return string
 *   Generated attribute.
 */
function ctools_api_html_name_from_array(array $parents) {
  return array_shift($parents) . (count($parents) > 1 ? '[' . implode('][', $parents) . ']' : '');
}

/**
 * Build theme hook.
 *
 * @param string $plugin_name
 *   Plugin namespace.
 * @param string $variant
 *   Theme variant.
 *
 * @return string
 *   Theme hook name.
 */
function ctools_api_theme_hook($plugin_name, $variant) {
  $arguments = array_merge(['ctools'], explode('\\', $plugin_name));
  $arguments[] = str_replace('-', '_', $variant);

  return implode('__', array_map('ctools_api_to_underscore', $arguments));
}

/**
 * Get CTools API content types.
 *
 * @param string $namespace
 *   Full namespace of a plugin object.
 *
 * @return \stdClass[]
 *   Panel panes.
 */
function ctools_api_get_panes_of_type($namespace) {
  return db_select('panels_pane', 'pp')
    ->fields('pp')
    ->condition('type', 'ctools_api')
    ->condition('subtype', $namespace)
    ->condition('shown', 1)
    ->execute()
    ->fetchAll();
}

/**
 * Apply theme hook.
 *
 * @param string $plugin_name
 *   Plugin machine name.
 * @param array $conf
 *   Values from configuration form.
 * @param array $plugin
 *   Plugin definition information.
 * @param array $variables
 *   An array of variables that will be passed to template.
 *
 * @throws \Exception
 *   When theme is not initialized.
 * @throws \RuntimeException
 *   When passed an incorrect plugin definition or settings.
 *
 * @return string
 *   HTML content.
 */
function ctools_api_apply_theme($plugin_name, array $conf, array $plugin, array $variables) {
  static $registry = [];

  if (isset($conf['theme'], $plugin['object'], $plugin['theme hooks'])) {
    $hook = $plugin['theme hooks'][$conf['theme']];

    if (empty($registry)) {
      $registry = theme_get_registry();
    }

    if (isset($registry[$hook])) {
      foreach ([
        'css' => [],
        // Add scripts before closing "body" tag.
        'js' => ['scope' => 'footer'],
      ] as $asset => $options) {
        // Replace all "templates" words in a path.
        $file = str_replace('templates', $asset, "{$registry[$hook]['path']}/{$registry[$hook]['template']}.$asset");

        if (file_exists($file)) {
          call_user_func("drupal_add_$asset", $file, $options);
        }
      }

      return theme(ctools_api_theme_hook($plugin_name, $conf['theme']), $variables);
    }

    watchdog(CTOOLS_API_MODULE_TITLE, '%hook theme hook not found in registry.', [
      '%hook' => $hook,
    ]);

    return t('You must create at least one template to output content.');
  }

  throw new \RuntimeException(t('Wrong invocation of @function function..', [
    '@function' => __FUNCTION__,
  ]));
}

/**
 * Base configuration form for all plugins that could be configurable.
 *
 * @param array $form
 *   Form elements implementation.
 * @param array $form_state
 *   Drupal form state.
 */
function ctools_api_plugin_base_configuration_form(array &$form, array &$form_state) {
  $plugin = ctools_api_form_state_get_plugin($form_state);

  if (!empty($plugin) && class_exists($plugin['object'])) {
    $reflection = new \ReflectionClass($plugin['object']);
    $items = [];

    // Collect all file names of parent classes. This is necessary, because
    // the form will not know anything about files with classes after
    // obtaining from cache.
    while ($reflection = $reflection->getParentClass()) {
      $file = trim(str_replace(DRUPAL_ROOT, '', $reflection->getFileName()), '/');
      $form_state['build_info']['files'][$file] = $file;
    }

    $form_state['input'] = array_merge($form_state['conf'], $form_state['input']);
    // Add default theme variant (if not exist) to configuration.
    $form_state['input'] += ['theme' => 'default'];
    $form['#attributes']['class'][] = 'variant-' . $form_state['input']['theme'];

    if (isset($form_state['triggering_element'])) {
      $trigger = $form_state['triggering_element'];

      // Process collections.
      if (isset($trigger['#operation'])) {
        $item =& drupal_array_get_nested_value($form_state['input'], array_slice($trigger['#parents'], 0, -2));
        $form_state['executed'] = FALSE;

        switch ($trigger['#operation']) {
          // @code
          // ['content', 'references', 'references', '_last', '_add']
          // @endcode
          case 'add':
            // Add new empty item to collection.
            $item[] = [];
            break;

          // @code
          // ['multiple', 2, '_operations', '_remove']
          // @endcode
          case 'remove':
            // Remove all values from the collection item.
            $item = NULL;
            // Get all items in collection.
            $item =& drupal_array_get_nested_value($form_state['input'], array_slice($trigger['#parents'], 0, -3));
            // Remove empty values.
            $item = array_values(array_filter($item));

            // If the last row was removed then init an empty.
            // @see \CTools\Form\Elements\Collection
            if (empty($item)) {
              $item = NULL;
            }
            break;
        }
      }
    }

    $plugin['object']::configurationForm($items, $form_state, $form_state['input']);

    if (!empty($plugin['theme variants'])) {
      $items = array_merge([
        'theme' => [
          '#ajax' => TRUE,
          '#type' => 'select',
          '#title' => t('Theme variant'),
          '#options' => $plugin['theme variants'],
          '#default_value' => $form_state['input']['theme'],
        ],
      ], $items);
    }

    $form += ctools_api_plugin_base_configuration_form_process($items, $form_state, $form_state['input'], $plugin);
    // Attach the file with plugin definition to the form to be
    // sure that everything will be okay on rebuilding state.
    $form_state['build_info']['files']['ctools_api'] = $plugin['location'];

    foreach (['css', 'js'] as $extension) {
      // Attach "form.css" and "form.js" provided by
      // CTools API for customizing configuration form.
      $form['#attached'][$extension][] = [
        'data' => CTOOLS_API_MODULE_PATH . "/$extension/form.$extension",
        'weight' => -10000,
      ];

      // Attach CSS and/or JS files that located near the "*.inc" file
      // with a content type definition (if exists).
      $plugin_asset = rtrim($plugin['location'], 'inc') . $extension;

      if (file_exists($plugin_asset)) {
        $form['#attached'][$extension][] = $plugin_asset;
      }
    }
  }
}

/**
 * Process form field types.
 *
 * @internal
 *
 * @param array $items
 *   Form elements implementation.
 * @param array $form_state
 *   Drupal form state.
 * @param array $conf
 *   Values from configuration form.
 * @param array $plugin
 *   Plugin definition information.
 * @param bool $add_to_tree
 *   Indicate that element should be added to list or not.
 *
 * @return array
 *   Processed items.
 */
function ctools_api_plugin_base_configuration_form_process(array $items, array &$form_state, array $conf, array $plugin, $add_to_tree = TRUE) {
  foreach ($items as $name => &$element) {
    $type = isset($element['#type']) ? $element['#type'] : '';

    if ($add_to_tree) {
      $form_state['#elements'][] = $name;
    }

    // Allow "#ajax => TRUE".
    if (isset($element['#ajax'])) {
      $element['#ajax'] = [
        'callback' => 'ctools_api_plugin_base_configuration_form_ajax',
      ];
    }

    switch ($type) {
      case 'horizontal_tabs':
        $element = array_merge($element, [
          '#tree' => TRUE,
          '#prefix' => '<div class="form-item horizontal-tabs" id="form-item-' . $name . '">',
          '#suffix' => '</div>',
        ]);

        unset($element['#type']);
        break;

      case 'horizontal_tab':
        $element = array_merge($element, [
          '#type' => 'fieldset',
        ]);
        break;

      case 'link_field':
        $titles = [
          'url' => t('URL'),
          'title' => t('Title'),
        ];

        $element = array_merge($element, ctools_api_element_prefix('link', $element), [
          '#tree' => TRUE,
          'title' => [
            '#type' => 'textfield',
            '#title' => $titles['title'],
            '#attributes' => [
              'placeholder' => $titles['title'],
            ],
          ],
          'url' => [
            '#type' => 'textfield',
            '#title' => $titles['url'],
            '#attributes' => [
              'placeholder' => $titles['url'],
            ],
          ],
        ]);

        unset($element['#type']);
        break;
    }

    $conf_child = $conf;

    if (isset($conf[$name])) {
      $conf_child = $conf[$name];

      if (is_array($conf[$name]) && isset($conf[$name]['value'])) {
        $conf[$name] = $conf[$name]['value'];
      }

      $element['#default_value'] = $conf[$name];
    }

    // Make our processing recursive.
    foreach (element_children($element) as $child) {
      // Re-run processing only for elements.
      if (is_array($element[$child])) {
        $data = call_user_func_array(__FUNCTION__, [[$child => $element[$child]], &$form_state, $conf_child, $plugin, empty($element['#tree'])]);
        $element[$child] = reset($data);
      }
    }
  }

  return $items;
}

/**
 * AJAX requests handler.
 *
 * @internal
 *
 * @param array $form
 *   Form elements implementation.
 * @param array $form_state
 *   Drupal form state.
 *
 * @return array
 *   AJAX commands.
 */
function ctools_api_plugin_base_configuration_form_ajax(array $form, array &$form_state) {
  ctools_include('modal');

  $plugin = ctools_api_form_state_get_plugin($form_state);
  $commands = [];

  $plugin['object']::configurationFormElementCallback(
    $form,
    $form_state,
    $form_state['values'],
    $commands,
    $form_state['triggering_element']
  );

  // Restore title of the modal window.
  if (isset($form_state['form_info']['order']['form'])) {
    $form_state['title'] = $form_state['form_info']['order']['form'];
  }

  return [
    '#type' => 'ajax',
    '#commands' => array_merge(ctools_modal_form_render($form_state, $form), $commands),
  ];
}

/**
 * {@inheritdoc}
 *
 * @see ctools_api_plugin_base_configuration_form()
 * @internal
 */
function ctools_api_plugin_base_configuration_form_validate(array $form, array &$form_state) {
  $plugin = ctools_api_form_state_get_plugin($form_state);

  if (isset($plugin['object'])) {
    $plugin['object']::configurationFormValidate($form, $form_state, $form_state['values']);
  }
}

/**
 * {@inheritdoc}
 *
 * @see ctools_api_plugin_base_configuration_form()
 * @internal
 */
function ctools_api_plugin_base_configuration_form_submit(array $form, array &$form_state) {
  $plugin = ctools_api_form_state_get_plugin($form_state);

  if (!empty($form_state['#elements']) && isset($plugin['object'])) {
    ctools_api_plugin_base_configuration_form_process_specific_elements_submit($form, $form_state);

    foreach ($form_state['#elements'] as $field_name) {
      if (isset($form_state['values'][$field_name])) {
        $form_state['conf'][$field_name] = $form_state['values'][$field_name];
      }
    }

    $plugin['object']::configurationFormSubmit($form, $form_state, $form_state['conf']);

    // @see ctools_api_form_alter()
    if (!empty($form_state['#nested_required'])) {
      $form_state['values']['settings'] = $form_state['conf'];
    }
  }

  // Save display style settings.
  // @see \panels_renderer_editor::get_style()
  // This defaults will be applied when new region will be created.
  // @see ctools_api_panels_flexible_add_item_form_submit()
  if (isset($form_state['type'], $form_state['renderer']) && 'display' === $form_state['type']) {
    // Configuration MUST be stored in cache, and, when "Update and save" button
    // will be clicked, then all data from cache will transferred to database.
    $renderer =& $form_state['renderer'];
    $renderer->cache->display->panel_settings['style_settings']['default'] = $form_state['conf'];
    // @todo Create a patch to Panels and remove this line.
    panels_edit_cache_set($renderer->cache);
  }
}

/**
 * Apply display default style to newly created region.
 *
 * @internal
 *
 * @see panels_ajax_flexible_edit_add()
 *
 * @param array $form
 *   Form elements implementation.
 * @param array $form_state
 *   Drupal form state.
 */
function ctools_api_panels_flexible_add_item_form_submit(array $form, array &$form_state) {
  $panel_settings =& $form_state['display']->panel_settings;

  // Apply display default style to newly created region.
  $panel_settings[$form_state['key']]['style'] = $panel_settings['style'];
  // Transfer setting of default style to newly created region.
  $panel_settings['style_settings'][$form_state['key']] = $panel_settings['style_settings']['default'];
}

/**
 * Recursive processing for specific form elements (e.g. "managed_file").
 *
 * @internal
 *
 * @param array $element
 *   Form element.
 * @param array $form_state
 *   Drupal form state.
 */
function ctools_api_plugin_base_configuration_form_process_specific_elements_submit(array $element, array &$form_state) {
  global $user;
  static $once = [];

  // Process the files.
  if (isset($element['#type'], $element['#name']) && 'managed_file' === $element['#type'] && empty($once[$element['#name']])) {
    managed_file_element_submit($element, $form_state, ['ctools_api', 'user', $user->uid]);

    $once[$element['#name']] = TRUE;
  }

  // Process collections.
  // @see \CTools\Plugins\ContentTypes\Form\Elements\Collection
  if (isset($element['#subtype'], $element['#id']) && 'collection' === $element['#subtype'] && empty($once[$element['#id']])) {
    $items =& drupal_array_get_nested_value($form_state['values'], $element['#parents']);

    // Remove buttons.
    foreach ($items as &$item) {
      unset($item['_operations'], $item['_add']);
    }

    // Remove empty items.
    $items = array_filter($items);

    $once[$element['#id']] = TRUE;
  }

  // Recursively call this function for sure that all field
  // will be saved correctly.
  foreach (element_children($element) as $child) {
    call_user_func_array(__FUNCTION__, [$element[$child], &$form_state]);
  }
}

/**
 * Prefix and suffix to wrap fields.
 *
 * @internal
 *
 * @param string $type
 *   Element type.
 * @param array $element
 *   Element definition
 *
 * @return string[]
 *   HTML wrapper markup.
 */
function ctools_api_element_prefix($type, array &$element) {
  $title = '';
  $description = '';

  if (!empty($element['#title'])) {
    $title = '<label>' . $element['#title'] . '</label>';
  }

  if (!empty($element['#description'])) {
    $description = '<div class="description">' . $element['#description'] . '</div>';
  }

  unset($element['#description']);

  return [
    '#prefix' => '<div class="form-item form-item-' . $type . '">' . $title . '<div class="form-' . $type . '-item-wrapper">',
    '#suffix' => '</div>' . $description . '</div>',
  ];
}

/**
 * Get plugin definition information from a $form_state.
 *
 * @param array $form_state
 *   Drupal form state.
 *
 * @throws \RuntimeException
 *   When plugin does not exists in a $form_state.
 *
 * @return array
 *   Plugin definition information.
 */
function ctools_api_form_state_get_plugin(array $form_state) {
  // Style plugins.
  if (isset($form_state['style'])) {
    return $form_state['style'];
  }

  // Content type plugins.
  if (isset($form_state['subtype_name'], $form_state['plugin']['content types'][$form_state['subtype_name']])) {
    return $form_state['plugin']['content types'][$form_state['subtype_name']];
  }

  // Access plugins.
  if (isset($form_state['plugin'])) {
    return $form_state['plugin'];
  }

  throw new \RuntimeException(t('Oops, plugin definition does not exists in a $form_state.'));
}
