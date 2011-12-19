<?php
// $Id: views_handler_filter_order_status.inc,v 1.1 2009/03/09 09:36:12 madsph Exp $
/**
 * Filter by order status
 * Thank you river_t for the Patch!
 */
class views_handler_filter_college extends views_handler_filter_many_to_one {
  
  function construct() {
    parent::construct();
    $this->content_field = content_fields('field_college_name');
    $field = $this->content_field;
    $this->value_title = $field['widget']['label'];
  }
  
  function option_definition() {
    $options = parent::option_definition();

    $options['value']['default'] = '<Any>';

    return $options;
  }
  
  function get_value_options() {
    $this->value_options = $this->allowed_values();
  }

  // Get allowed values from hook_allowed_values(), if any,
  // or from content_allowed_values();
  function allowed_values() {
    $field = $this->content_field;
    $function = $field['module'] .'_allowed_values';
    if ($this->value_form_type == 'select') {
      // Select elements accept multidimensional arrays to support optgroups.
      $options = function_exists($function) ? $function($field) : content_allowed_values($field, FALSE);
      // For selects, HTML should be filtered out and entities left unencoded.
      // See content_allowed_values / content_filter_xss / filter_xss.
      content_allowed_values_filter_html($options);
    }
    else {
      $options = function_exists($function) ? $function($field) : content_allowed_values($field);
    }
    return (array) $options;
  }
}
