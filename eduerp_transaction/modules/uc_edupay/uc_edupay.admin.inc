<?php 

/**
 * @file
 * Admin configuration settings for edupay
 */ 

/**
 * Settings for edupay invoicing
 */ 
function uc_edupay_invoice_settings_form() {
  $form['uc_edupay_invoice_note'] = array(
    '#type' => 'textarea',
    '#title' => t('Invoice note'),
    '#description' => t("Provide extra notes on invoice for students. <a href=\"!url\">Uses order and global tokens</a>.", array('!url' => url('admin/store/help/tokens'))),
    '#summary' => variable_get('uc_edupay_invoice_note', '') ? t('Invoice notes is set.') : t('Invoice note is not set.'),
    '#default_value' => variable_get('uc_edupay_invoice_note', ''),
    '#rows' => 3,
  );
  $form['uc_edupay_invoice_note_format'] = filter_form(variable_get('uc_edupay_invoice_note_format', FILTER_FORMAT_DEFAULT), NULL, array('uc_edupay_invoice_note_format'));
  
  return system_settings_form($form);
}