<?php 

/**
 * Implementation of hook_views_default_views().
 */
function uc_edupay_views_default_views() {
  /*
   * View 'pdf_orders'
   * 
   * This view is provided originally by uc_pdf_invoice module. We need
   * to disable it by overriding it.
   */
$view = new view;
$view->name = 'pdf_orders';
$view->description = 'PDF Order listing';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'uc_orders';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'uid' => array(
    'label' => 'Uid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_user' => 0,
    'exclude' => 1,
    'id' => 'uid',
    'table' => 'users',
    'field' => 'uid',
    'override' => array(
      'button' => 'Übersteuern',
    ),
    'relationship' => 'none',
  ),
  'order_id' => array(
    'label' => 'Order id',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 1,
      'path' => 'user/[uid]/order/[order_id]',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'link_to_order' => 0,
    'exclude' => 0,
    'id' => 'order_id',
    'table' => 'uc_orders',
    'field' => 'order_id',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Übersteuern',
    ),
  ),
  'order_status' => array(
    'label' => 'Order Status',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'order_status',
    'table' => 'uc_orders',
    'field' => 'order_status',
    'override' => array(
      'button' => 'Übersteuern',
    ),
    'relationship' => 'none',
  ),
  'created' => array(
    'label' => 'Date',
    'date_format' => 'small',
    'custom_date_format' => '',
    'exclude' => 0,
    'id' => 'created',
    'table' => 'uc_orders',
    'field' => 'created',
    'relationship' => 'none',
  ),
  'order_total' => array(
    'label' => 'Total',
    'exclude' => 0,
    'id' => 'order_total',
    'table' => 'uc_orders',
    'field' => 'order_total',
    'relationship' => 'none',
  ),
  'nothing_1' => array(
    'label' => 'Invoice',
    'alter' => array(
      'text' => 'Invoice',
      'make_link' => 1,
      'path' => 'invoice/pdf/[order_id]',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '_blank',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
      'strip_tags' => 0,
    ),
    'empty' => '',
    'hide_empty' => 0,
    'empty_zero' => 0,
    'exclude' => 0,
    'id' => 'nothing_1',
    'table' => 'views',
    'field' => 'nothing',
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'uid_current' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'uid_current',
    'table' => 'users',
    'field' => 'uid_current',
    'relationship' => 'none',
  ),
  'order_status' => array(
    'operator' => 'not in',
    'value' => array(
      'in_checkout' => 'in_checkout',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'order_status',
    'table' => 'uc_orders',
    'field' => 'order_status',
    'override' => array(
      'button' => 'Übersteuern',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('title', 'PDF Orders');
$handler->override_option('items_per_page', 25);
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'table');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 0,
  'order' => 'desc',
  'columns' => array(
    'order_id' => 'order_id',
    'name' => 'name',
    'primary_email' => 'name',
    'created' => 'created',
    'order_total' => 'order_total',
    'country_name' => 'name',
  ),
  'info' => array(
    'order_id' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'separator' => '<br/>',
    ),
    'primary_email' => array(
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'order_total' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'country_name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  ),
  'default' => 'order_id',
));
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->override_option('path', 'user/%/orders');
$handler->override_option('menu', array(
  'type' => 'tab',
  'title' => 'Orders',
  'description' => '',
  'weight' => '0',
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));

$views[$view->name] = $view;

  return $views;
  
}
