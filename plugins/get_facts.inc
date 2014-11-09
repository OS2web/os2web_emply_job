<?php

/**
 * @file
 * Extract facts from the $result object.
 */

$plugin = array(
  'form' => 'os2web_emply_job_get_facts_form',
  'callback' => 'os2web_emply_job_get_facts_callback',
  'name' => 'Get facts',
  'multi' => 'loop',
  'category' => 'OS2Web Emply Job',
);

/**
 * Plugin form.
 */
function os2web_emply_job_get_facts_form($importer, $element_key, $settings) {
  $form = array();
  $form['no_configuration'] = array(
    '#markup' => t('No configuration needed.'),
  );
  return $form;
}

/**
 * Plugin callback.
 */
function os2web_emply_job_get_facts_callback($result, $item_key, $element_key, &$field, $settings) {
  $result = $result->items[$item_key];

  if (!empty($result['xpathparser:8'])) {
    $doc = new DOMDocument();
    $doc->loadXML($result['xpathparser:8']);
    $xpath = new DOMXpath($doc);
    $elements = $xpath->query("/facts/fact[@visible='True']");
    $facts = array();

    foreach ($elements as $element) {
      $facts[] = array(
        'label' => $element->attributes->getNamedItem('title')->nodeValue,
        'value' => $element->nodeValue,
      );
    }

    $field = theme('os2web_emply_job_facts', array('facts' => $facts));
  }
}