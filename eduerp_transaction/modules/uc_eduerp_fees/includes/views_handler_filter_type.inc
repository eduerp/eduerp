<?php 

class views_handler_filter_type extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Fees type');
      $fees_order_type = uc_edupay_fees_order_get_item('type');
      foreach ($fees_order_type as $key => $type) {
        //$options[$name['id']] = $name['title'];
        $options[$type['type']] = $type['type'];
      }
      $this->value_options = $options;
    }
  }
}