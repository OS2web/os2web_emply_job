<?php
/**
 * @file
 * os2web_emply_job.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function os2web_emply_job_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-blank_source_1-get_and_return_emply_domain';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'get_emply_domain';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Get and return Emply domain';
  $export['os2web_emply_job-blank_source_1-get_and_return_emply_domain'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-blank_source_1-rewrite';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[Blank source 1]/recruitment/vacancyad.aspx?vacancyid=[xpathparser:2]',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite to correct advertisement URL';
  $export['os2web_emply_job-blank_source_1-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-blank_source_2-get_and_return_emply_domain';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'get_emply_domain';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Get and return Emply domain';
  $export['os2web_emply_job-blank_source_2-get_and_return_emply_domain'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-blank_source_2-rewrite';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[Blank source 2]/recruitment/vacancyapply.aspx?vacancyid=[xpathparser:2]
',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite to correct application form URL';
  $export['os2web_emply_job-blank_source_2-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-xpathparser_1-clean_up_body_field';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'clean_up_body';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Clean up body field';
  $export['os2web_emply_job-xpathparser_1-clean_up_body_field'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-xpathparser_5-get_and_return_emply_domain';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'get_emply_domain';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Get and return Emply domain';
  $export['os2web_emply_job-xpathparser_5-get_and_return_emply_domain'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-xpathparser_7-get_position_category';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'get_position_category';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Get position category';
  $export['os2web_emply_job-xpathparser_7-get_position_category'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'os2web_emply_job-xpathparser_8-get_facts';
  $feeds_tamper->importer = 'os2web_emply_job';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'get_facts';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Get facts';
  $export['os2web_emply_job-xpathparser_8-get_facts'] = $feeds_tamper;

  return $export;
}
