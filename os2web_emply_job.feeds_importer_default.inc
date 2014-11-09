<?php
/**
 * @file
 * os2web_emply_job.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function os2web_emply_job_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'os2web_emply_job';
  $feeds_importer->config = array(
    'name' => 'OS2Web Emply Job',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'adheader[@language=\'da-DK\']',
          'xpathparser:1' => 'ad[@language=\'da-DK\']',
          'xpathparser:2' => 'publishingid',
          'xpathparser:3' => 'adid',
          'xpathparser:4' => 'deadline',
          'xpathparser:7' => 'facts',
          'xpathparser:8' => 'facts',
        ),
        'rawXML' => array(
          'xpathparser:7' => 'xpathparser:7',
          'xpathparser:8' => 'xpathparser:8',
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '//root/vacancy',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_emply_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_emply_application_due:start',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_emply_position_category',
            'unique' => FALSE,
            'term_search' => '0',
            'autocreate' => 1,
          ),
          6 => array(
            'source' => 'Blank source 1',
            'target' => 'field_emply_advertisement_url:url',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Blank source 2',
            'target' => 'field_emply_application_form_url:url',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_emply_facts',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'emply_job_html',
        'skip_hash_check' => 0,
        'bundle' => 'os2web_emply_job',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '3600',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['os2web_emply_job'] = $feeds_importer;

  return $export;
}
