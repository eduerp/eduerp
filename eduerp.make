; ----------------
; EduERP makefile
; ----------------
;  
; Core version
; ------------
; Core version of Drupal that projects should be compatible with.
; 
  
core = 6.x
  
; API version
; ------------
; Drush Make API version. This version of drush make uses API version `2`.
;
 
api = 2
  
; Core project
; ------------  
; Drupal 6.x core:

projects[] = drupal
  
  
; Modules
; --------
projects[adminrole][version] = 1.3
projects[adminrole][type] = "module"
projects[admin_menu][version] = 1.8
projects[admin_menu][type] = "module"
projects[cck][version] = 2.9
projects[cck][type] = "module"
projects[filefield][version] = 3.10
projects[filefield][type] = "module"
projects[imagefield][version] = 3.10
projects[imagefield][type] = "module"
projects[content_profile][version] = 1.0
projects[content_profile][type] = "module"
projects[date][version] = 2.9
projects[date][type] = "module"
projects[devel][version] = 1.27
projects[devel][type] = "module"
projects[features][version] = 1.2
projects[features][type] = "module"
projects[imageapi][version] = 1.10
projects[imageapi][type] = "module"
projects[imagecache][version] = 2.0-rc1
projects[imagecache][type] = "module"
projects[advanced_help][version] = 1.2
projects[advanced_help][type] = "module"
projects[auto_nodetitle][version] = 1.2
projects[auto_nodetitle][type] = "module"
projects[backup_migrate][version] = 2.6
projects[backup_migrate][type] = "module"
projects[pathauto][version] = 1.6
projects[pathauto][type] = "module"
projects[rules][version] = 1.5
projects[rules][type] = "module"
projects[skinr][version] = 1.6
projects[skinr][type] = "module"
projects[token][version] = 1.19
projects[token][type] = "module"
projects[transliteration][version] = 3.1
projects[transliteration][type] = "module"
projects[ubercart][version] = 2.11
projects[ubercart][type] = "module"
projects[print][version] = 1.18
projects[print][type] = "module"
projects[ckeditor][version] = 1.13
projects[ckeditor][type] = "module"
projects[jquery_update][version] = 2.0-alpha1
projects[jquery_update][type] = "module"
projects[views][version] = 2.16
projects[views][type] = "module"
projects[] = ajax_load
projects[] = computed_field
projects[] = autoload
projects[] = form_panel
projects[] = glossary
projects[] = ctools
projects[] = strongarm
projects[] = schema
projects[] = dbtuner
projects[] = services
projects[] = views_customfield
projects[] = views_pdf
projects[] = views_watchdog
projects[] = uc_views
projects[] = zimbra
projects[] = views_data_export
projects[] = mimemail 
projects[] = views_pdf_mimemail
projects[] = uc_rules
projects[eduerp][type] = "module"
projects[eduerp][download][type] = "git"
projects[eduerp][download][url] = "https://github.com/eduerp/eduerp.git"
projects[editablefields][type] = "module"
projects[editablefields][download][type] = "git"
projects[editablefields][download][url] = "https://github.com/eduerp/editablefields.git"
  

; Themes
; --------
projects[fusion][version] = 1.13
projects[fusion][type] = "theme"

  
  
; Libraries
; ---------
libraries[ckeditor][type] = "libraries"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.0/ckeditor_4.0_standard.zip"
libraries[fpdi][type] = "libraries"
libraries[fpdi][download][type] = "file"
libraries[fpdi][download][url] = "http://www.setasign.de/supra/kon2_dl/55450/FPDI-1.4.3.zip"
libraries[fpdf_tpl][type] = "libraries"
libraries[fpdf_tpl][download][type] = "file"
libraries[fpdf_tpl][download][url] = "http://www.setasign.de/supra/kon2_dl/55452/FPDF_TPL-1.2.1.zip"
libraries[wkhtmltopdf][type] = "libraries"
libraries[wkhtmltopdf][download][type] = "file"
libraries[wkhtmltopdf][download][url] = "http://wkhtmltopdf.googlecode.com/files/wkhtmltopdf-0.11.0_rc1-static-i386.tar.bz2"

