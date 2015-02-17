<?php
/**
 * @file
 * Settings page for the os2web_emply_job module.
 */

/**
 * System settings form for configuration of the Emply job import.
 */
function os2web_emply_job_settings_form($form, $form_state) {
  module_load_include('inc', 'feeds', 'feeds.pages');
  $importer_id = OS2WEB_EMPLY_JOB_FEEDS_MACHINE_NAME;

  // Settings form
  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
  );
  $form['settings']['position_category_guid'] = array(
    '#type' => 'textfield',
    '#title' => t('Position category GUID'),
    '#description' => t('The GUID attribute from the facts node containing the position category.'),
    '#default_value' => variable_get('os2web_emply_job_position_category_guid', ''),
    '#size' => 60,
  );
  $form['settings']['feeds_source_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Feeds source URL'),
    '#description' => t('Enter the feed source URL for the Emply Job importer.'),
    '#default_value' => os2web_emply_job_feeds_url_get(),
    '#size' => 60,
  );
  $form['settings']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
    '#submit' => array('os2web_emply_job_settings_submit'),
  );

  // Showing the current import status
  if (feeds_access('import', $importer_id) || feeds_access('clear', $importer_id) || feeds_access('unlock', $importer_id)) {
    $source = feeds_source($importer_id);
    $form['status'] = array(
      '#type' => 'fieldset',
      '#title' => t('Status'),
      '#value' => feeds_source_status($source),
    );
    $form['actions'] = array(
      '#type' => 'fieldset',
      '#title' => t('Actions'),
    );
    // Various hidden fields used by the action buttons.
    $form['#redirect'] = os2web_emply_job_config_path() . '/os2web_emply_jobs';
    $form['#importer_id'] = $importer_id;
  }

  // Actions: import button
  if (feeds_access('import', $importer_id)) {
    $import = feeds_import_form(array(), $form_state, $importer_id);
    $form['actions']['import_submit'] = $import['submit'];
    $form['actions']['import_submit']['#submit'] = array('feeds_import_form_submit');
    unset($form['actions']['submit']);
  }

  // Actions: delete button
  if (feeds_access('clear', $importer_id)) {
    $delete = feeds_delete_tab_form(array(), $form_state, $importer_id);
    $form['actions']['delete_submit'] = $delete['actions']['submit'];
    $form['actions']['delete_submit']['#submit'] = array('feeds_delete_tab_form_submit');
    $form['actions']['delete_submit']['#value'] = t('Delete items');
  }

  // Actions: unlock button
  if (feeds_access('unlock', $importer_id)) {
    $unlock = feeds_unlock_tab_form(array(), $form_state, $importer_id);
    $form['actions']['unlock_submit'] = $unlock['actions']['submit'];
    $form['actions']['unlock_submit']['#submit'] = array('feeds_unlock_tab_form_submit');
  }

  // Some of the feeds forms are overwriting the page tile, so we set it agian.
  drupal_set_title(t('OS2Web Emply Job'));

  return $form;
}

/**
 * Submit callback; save Emply job settings.
 *
 * @ingroup forms
 */
function os2web_emply_job_settings_submit($form, &$form_state) {
  variable_set('os2web_emply_job_position_category_guid', $form_state['values']['position_category_guid']);
  os2web_emply_job_feeds_url_set($form_state['values']['feeds_source_url']);
  drupal_set_message(t('Settings saved successfully!'));
}

function os2web_emply_job_log_view() {
  // Setting page title
  drupal_set_title(t('Log for the Emply job importer'));

  // Embedding view
  $data = views_embed_view('feeds_log', 'page_1', OS2WEB_EMPLY_JOB_FEEDS_MACHINE_NAME);

  // Fixing wrong form action in exposed filter form
  $data = str_replace('import/os2web_emply_job/log', $_GET['q'], $data);

  return $data;
}