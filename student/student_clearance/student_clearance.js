/* 
 * @file
 * Handle pdf agreement download after successful file actions
 */

var displayUrl = function(response) {

    var result = Drupal.parseJson(response);
    //$(id of the field to update with the value of the link).append
    //$('agreement-ajax-result').html(result.data);

}

Drupal.behaviors.student_clearance = function(context) {

    var url = Drupal.settings.student_clearance.agreement_url;
    var href_value = Drupal.settings.student_clearance.href_value;
    //Drupal.t('text');
    
    var htmlstring = '<a href="' + url + '">Download PDF Agreement</a>';
    
    $('.editablefields-form-agreement-agree input:not(.editablefields-processed)', context).addClass('editablefield-form-agreement-agree-processed').bind('click', function() {

        //$('.agreement-ajax-result').html(htmlstring);
        //$.get(url, null, displayUrl);
		
        // this is happening on success of the above .get code
        //$('.editablefields-form-agreement-agree input').attr("checked", "checked");
        $('.editablefields-form-agreement-agree input').attr("disabled", "disabled");

    });
}
