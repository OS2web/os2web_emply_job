<?php

/**
 * @file
 * Removing inline styles from the body field.
 */

$plugin = array(
  'form' => 'os2web_emply_job_clean_up_body_form',
  'callback' => 'os2web_emply_job_clean_up_body_callback',
  'name' => 'Clean up body field',
  'multi' => 'loop',
  'category' => 'OS2Web Emply Job',
);

/**
 * Plugin form.
 */
function os2web_emply_job_clean_up_body_form($importer, $element_key, $settings) {
  $form = array();
  $form['no_configuration'] = array(
    '#markup' => t('No configuration needed.'),
  );
  return $form;
}

/**
 * Plugin callback.
 */
function os2web_emply_job_clean_up_body_callback($result, $item_key, $element_key, &$field, $settings) {
  $field = check_markup($field, 'emply_job_html');
  $field = preg_replace('/&lt;\?xml[^>]+\/&gt;/i', '', $field);
  $field = preg_replace('/(<[^>]+) class=".*?"/i', '$1', $field);
}
