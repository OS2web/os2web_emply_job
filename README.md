OS2Web Emply Job
================

OS2Web Drupal feature for importing jobs from Emply.net to a content type in Drupal. It also includes a list of jobs with category filter.

OS2Web Emply Job
=================

Description
-----------
Content type, Feeds importer, Views and Panel page for displaying vacancies from Emply.net.

Installation and configuration
------------------------------
This feature should reside in the modules directory of the installation,
most commonly profiles/profile-name/modules, but alternately in 
sites/all/modules (This could be for development purposes).

After you have enabled the feature, will you need to configure the GUID attribute value for the facts node containing the position
 categories. If you have either OS2Web Settings or OS2Web Settings Page modules installed, can the configuration be done
 from admin/config/os2web/os2web_emply_jobs. Alternatively can you set the GUID in your settings.php file using
 "$conf['os2web_emply_job_position_category_guid'] = 'GUID';".

Finally go to /import/os2web_emply_job and paste the GET URL to the Emply API. It looks like
 http://yourname.emply.net/api.asmx/GetVacancies?mediaId=YOUR-MEDIA-ID&apiKey=YOUR-API-KEY.

This module can also be installed with drush make in your install profile.

Additional Info
---------------
This repository should be governed using Git Flow. for more information see
http://nvie.com/posts/a-successful-git-branching-model/
