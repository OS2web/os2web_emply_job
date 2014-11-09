<?php

/**
 * @file
 * Finds the position category from the $result object.
 */

$plugin = array(
  'form' => 'os2web_emply_job_get_position_category_form',
  'callback' => 'os2web_emply_job_get_position_category_callback',
  'name' => 'Get position category',
  'multi' => 'loop',
  'category' => 'OS2Web Emply Job',
);

/**
 * Plugin form.
 */
function os2web_emply_job_get_position_category_form($importer, $element_key, $settings) {
  $form = array();
  $form['no_configuration'] = array(
    '#markup' => t('No configuration needed.'),
  );
  return $form;
}

/**
 * Plugin callback.
 */
function os2web_emply_job_get_position_category_callback($result, $item_key, $element_key, &$field, $settings) {
  $result = $result->items[$item_key];
  $category_guid = variable_get('os2web_emply_job_position_category_guid', '');

  if (!empty($category_guid) && !empty($result['xpathparser:7'])) {
    $doc = new DOMDocument();
    $doc->loadXML($result['xpathparser:7']);
    $xpath = new DOMXpath($doc);
    $elements = $xpath->query("/facts/fact[@id='" . $category_guid . "']");
    $field = !empty($elements->item(0)->nodeValue) ? $elements->item(0)->nodeValue : '';
  }
}