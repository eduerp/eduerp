<?php 

class views_handler_filter_scholarship_type extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Scholarship type');
      $scholarship_type = uc_edupay_fees_order_get_item('scholarship_type');
      foreach ($scholarship_type as $key => $value) {
        $options[$value['scholarship_type']] = $value['scholarship_type'];
      }
      $this->value_options = $options;
    }
  }
}