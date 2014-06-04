<?php
/**
 * @file
 * os2web_emply_job.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function os2web_emply_job_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'os2web_emply_job_list_page';
  $page->task = 'page';
  $page->admin_title = 'Job List Page';
  $page->admin_description = '';
  $page->path = 'job';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_job_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'os2web_emply_job_list_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'job-listing',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'robots' => array(
          'value' => array(
            'noindex' => 'noindex',
            'index' => 0,
            'follow' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noodp' => 0,
            'noydir' => 0,
          ),
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'header' => NULL,
      'blogs-list' => NULL,
      'sidebar' => NULL,
      'footer' => NULL,
      'top-full-section' => NULL,
      'table-list' => NULL,
      'middle-full-section' => NULL,
      'bottom-full-section' => NULL,
      'middle' => NULL,
    ),
    'header' => array(
      'style' => 'naked',
    ),
    'top-full-section' => array(
      'style' => 'naked',
    ),
    'table-list' => array(
      'style' => 'naked',
    ),
    'middle-full-section' => array(
      'style' => 'naked',
    ),
    'bottom-full-section' => array(
      'style' => 'naked',
    ),
    'footer' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = 'Vacancies';
  $display->uuid = '3822aa31-cdbc-40df-84d5-9d603feeba1b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-52e9a11e-7483-4dc2-ab51-e92ba3580b2b';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'os2web_emply_job_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 1,
      'pager_id' => '0',
      'items_per_page' => '25',
      'offset' => '0',
      'exposed' => array(
        'field_emply_position_category_tid' => 'All',
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '52e9a11e-7483-4dc2-ab51-e92ba3580b2b';
    $display->content['new-52e9a11e-7483-4dc2-ab51-e92ba3580b2b'] = $pane;
    $display->panels['middle'][0] = 'new-52e9a11e-7483-4dc2-ab51-e92ba3580b2b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['os2web_emply_job_list_page'] = $page;

  return $pages;

}
