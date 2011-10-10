/**
 * @file
 * Handle page elements without required redirects and refresh
 */

/**
 * Finding a way to trigger the pdf download without leaving the order page
 */

Drupal.behaviors.uc_edupay = function(context) {
    var pdfPath = Drupal.settings.uc_edupay.pdflink;
    // parse the data coming from the server. This is how AJAX response is handled in Drupal
    //$.get(pdfPath);
 
    //window.location(Drupal.settings.basePath + pdfPath);

    $('a.invoice-submit', context).bind('click', function(){
      window.open(Drupal.settings.basePath + pdfPath, "Save Invoice", "width=420,height=350,resizable=no,scrollbars=no,menubar=no,status=no,toolbar=no");
    });
}

/*$(document).ready(function(){
  var pdflink = Drupal.settings.uc_edupay.pdflink;
        window.alert(pdflink);
});*/

