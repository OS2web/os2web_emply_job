<?php

/**
 * @file
 * Finds the Emply domain from the $result object.
 */

$plugin = array(
  'form' => 'os2web_emply_job_get_emply_domain_form',
  'callback' => 'os2web_emply_job_get_emply_domain_callback',
  'name' => 'Get and return Emply domain',
  'multi' => 'loop',
  'category' => 'OS2Web Emply Job',
);

/**
 * Plugin form.
 */
function os2web_emply_job_get_emply_domain_form($importer, $element_key, $settings) {
  $form = array();
  $form['no_configuration'] = array(
    '#markup' => t('No configuration needed.'),
  );
  return $form;
}

/**
 * Plugin callback.
 */
function os2web_emply_job_get_emply_domain_callback($result, $item_key, $element_key, &$field, $settings) {
  $url = parse_url($result->link);
  $field = $url['scheme'] . '://' . $url['host'];
}
