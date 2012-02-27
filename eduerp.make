; EduERP Drush Makefile

core = 6.x
api = 2
projects[] = drupal

; Projects

; EduERP 
;projects[eduerp][download][type] = "git"
;projects[eduerp][download][url] = "git@dev.datasphir.com:eduerp"
;projects[eduerp][type] = "module"

; EduERP - editablefields
;projects[editablefields][download][type] = "git"
;projects[editablefields][download][url] = "git@dev.datasphir.com:editablefields"
;projects[editablefields][type] = "module"

; Drupal-Zimbra
;projects[zimbra][download][type] = "git"
;projects[zimbra][download][url] = "https://github.com/miglius/drupal-zimbra.git"
;projects[zimbra][type] = "module"

; Admin
projects[backup_migrate][subdir] = "contrib"
projects[advanced_help][subdir] = "contrib"

; CCK
projects[cck][subdir] = "contrib"
projects[computed_field][subdir] = "contrib"
projects[date][subdir] = "contrib"
;projects[editablefields][subdir] = "contrib"
projects[filefield][subdir] = "contrib"
projects[imagefield][subdir] = "contrib"

; Views
projects[views][subdir] = "contrib"
projects[views_pdf][subdir] = "contrib"
projects[views_customfield][subdir] = "contrib"
projects[views_watchdog][subdir] = "contrib"

; Development
projects[devel][subdir] = "contrib"
projects[features][subdir] = "contrib"
projects[schema][subdir] = "contrib"
projects[strongarm][subdir] = "contrib"

; Content
projects[auto_nodetitle][subdir] = "contrib"
projects[wysiwyg][subdir] = "contrib"
projects[ckeditor][subdir] = "contrib"
projects[print][subdir] = "contrib"
projects[glossary][subdir] = "contrib"
projects[content_profile][subdir] = "contrib"

; Images
projects[imageapi][subdir] = "contrib"
projects[imagecache][subdir] = "contrib"

; Paths
projects[pathauto][subdir] = "contrib"

; Services
projects[services][subdir] = "contrib"

; Other
projects[ctools][subdir] = "contrib"
projects[ajax_load][subdir] = "contrib"
projects[autoload][subdir] = "contrib"
projects[jquery_update][subdir] = "contrib"
projects[rules][subdir] = "contrib"
projects[google_analytics][subdir] = "contrib"
projects[token][subdir] = "contrib"
projects[transliteration][subdir] = "contrib"
projects[menu_item_container][subdir] = "contrib]"

; Ubercart
projects[ubercart][subdir] = "contrib"
projects[uc_pdf_invoice][subdir] = "contrib"
projects[uc_views][subdir] = "contrib"


; Themes/Theming
projects[fusion][type] = theme
projects[abessive][type] = theme
projects[skinr][subdir] = "contrib"
projects[form_panel][subdir] = "contrib"

; Libraries

; CKEditor
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.2/ckeditor_3.6.2.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"


; Profiler
libraries[profiler][download][type] = "get"
libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-6.x-2.0-beta1.tar.gz"
projects[profiler_builder][location] = https://drupal.psu.edu/fserver


