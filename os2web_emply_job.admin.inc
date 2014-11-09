<?php
/**
 * @file
 * Settings page for the os2web_emply_job module.
 */

/**
 * System settings form for configuration of the Emply job import.
 */
function os2web_emply_job_settings_form($form, $form_state) {
  $form['os2web_emply_job_position_category_guid'] = array(
    '#type' => 'textfield',
    '#title' => t('Position category GUID'),
    '#description' => t('The GUID attribute from the facts node containing the position category.'),
    '#default_value' => variable_get('os2web_emply_job_position_category_guid', ''),
    '#size' => 60,
  );
  return system_settings_form($form);
}