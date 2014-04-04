<?php
/**
 * @file
 * os2web_emply_job.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os2web_emply_job_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os2web_emply_job_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function os2web_emply_job_node_info() {
  $items = array(
    'os2web_emply_job' => array(
      'name' => t('OS2web Emply Job'),
      'base' => 'node_content',
      'description' => t('Content type storing open positions imported from Emply.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
