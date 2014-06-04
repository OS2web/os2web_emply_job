OS2Web Emply Job
================

OS2Web Drupal feature for importing jobs from Emply.net to a content type in Drupal. It also includes a list of jobs with category filter.

Enable the feature and go to /import/os2web_emply_job and paste the GET URL to the Emply API. It looks like http://yourname.emply.net/api.asmx/GetVacancies?mediaId=YOUR-MEDIA-ID&apiKey=YOUR-API-KEY.

OS2Web Emply Job
=================

Description
-----------
Content type, Feeds importer, Views and Panel page for displaying vacancies from Emply.net.

Installation
------------
This feature should reside in the modules directory of the installation,
most commonly profiles/profile-name/modules, but alternately in 
sites/all/modules (This could be for development purposes).

Enable the feature and go to /import/os2web_emply_job and paste the GET URL to
 the Emply API. It looks like 
 http://yourname.emply.net/api.asmx/GetVacancies?mediaId=YOUR-MEDIA-ID&apiKey=YOUR-API-KEY.

This module can also be installed with drush make in your install profile.

Additional Info
---------------
This repository should be governed using Git Flow. for more information see
http://nvie.com/posts/a-successful-git-branching-model/
