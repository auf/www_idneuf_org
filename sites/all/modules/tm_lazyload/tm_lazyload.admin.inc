<?php
/**
 * @file
 * TM Lazyload Admin
 *
 * @author: Daniel Honrade http://drupal.org/user/351112
 *
 */

/**
 * Admin Form: UI
 *
 */
function tm_lazyload_admin( $form, &$form_state, $op = NULL ) {

	global $_tm_lazyload_set;

	$settings = $_tm_lazyload_set;

	$form = array();

	$form['tm_lazyload'] = array(
		'#type'				=> 'fieldset',
		'#title'			=> 'TM Lazyload Configuration',
		'#collapsible'		=> TRUE,
		'#collapsed'		=> FALSE,
		'#tree'				=> TRUE,
		'#description'		=> t( '' ),
	);

	$form['tm_lazyload']['enabled'] = array(
		'#type'				=> 'checkbox',
		'#title'			=> t( 'Enabled' ),
		'#default_value'	=> $settings['enabled'],
		'#description'		=> t( 'Enable TM Lazyload' ),
		'#prefix'			=> '<div class="lazy-columns clearfix"><div class="lazy-column lazy-column-1">',
	);

	$form['tm_lazyload']['distance'] = array(
		'#type'				=> 'textfield',
		'#title'			=> t( 'Distance' ),
		'#default_value'	=> $settings['distance'],
		'#size'				=> 5,
		'#maxlength'		=> 5,
		'#description'		=> t( 'The distance (in pixels) of image to the viewable browser window before it loads the actual image.' ),
	);

	$form['tm_lazyload']['placeholder'] = array(
		'#type'				=> 'textfield',
		'#title'			=> t( 'Placeholder Image' ),
		'#default_value'	=> $settings['placeholder'],
		'#description'		=> t( 'Path to your placeholder image, ex. sites/default/files/placeholder_image.gif. Leave it blank to use the default image.' ),
	);

	$loader_dir = base_path() . drupal_get_path( 'module', 'tm_lazyload' ) . '/loader/';
	$loader = array( 0 => t( 'None' ) );
	for ( $i = 1; $i <= 8; $i++ ) {
		$loader[$i] = '<img alt="TM Lazyload Icon" src="' . $loader_dir . 'loader-' . $i . '.gif">';
	}

	$form['tm_lazyload']['loader_icon'] = array(
		'#type'				=> 'radios',
		'#title'			=> t( 'Loader Icon' ),
		'#options'			=> $loader,
		'#default_value'	=> $settings['loader_icon'],
		'#description'		=> t( 'This icon will show when the actual image is not yet fully loaded.' ),
		'#suffix'			=> '</div>',
	);

	$form['tm_lazyload']['exclude'] = array(
		'#type'				=> 'textarea',
		'#title'			=> t( 'Excluded Pages' ),
		'#default_value'	=> $settings['exclude'],
		'#description'		=> t( 'List the page paths to be excluded from lazyloading on each line. This is useful when you want to redirect your user with disabled javascript browser on pages with the same content but not using image lazyloading. Ex. node/1' ),
		'#prefix'			=> '<div class="lazy-column lazy-column-2">',
		'#suffix'			=> '</div></div>',
	);

	$form['save']			= array( '#type' => 'submit', '#value' => t( 'Save' ), );
	$form['reset']			= array( '#type' => 'submit', '#value' => t( 'Reset' ), );

	return $form;
}


/**
 * Admin Form: Submit
 *
 */
function tm_lazyload_admin_submit( $form, $form_state ) {

	global $_tm_lazyload_defaults;

	$form_values = $form_state['values'];

	if ( $form_values['op'] == 'Save' ) {
		$settings = $form_values['tm_lazyload']; // save user settings
	} elseif ( $form_values['op'] == 'Reset' ) {
		$settings = $_tm_lazyload_defaults;		// save default settings
	}

	variable_set( 'tm_lazyload', $settings );
}
