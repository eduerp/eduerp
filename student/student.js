/* 
 * @file
 *
 * Common js scripts for student module
 * Handle pdf agreement download after successful file actions
 */	

Drupal.behaviors.student = function(context) {
	
	// do yoyo if selected value is not nigeria, show state and lga
	
	var $country_field = $('#edit-field-profile-country-name-value');
	var $state_field = $('#edit-field-profile-state-name-origin-value-wrapper');
	var $lga_field = $('#edit-field-profile-lga-name-value-wrapper');

	$country_field.change( function () { 
		if($(this).val() != 'Nigeria') {
			$state_field.hide("slow");
			$lga_field.hide("slow");
		} else {
			$state_field.show("slow");
			$lga_field.show("slow");
		}
	} );
	
	// ensure title case is maintained in name fields
	
	var lastname_field = $('#edit-field-profile-last-name-0-value');
	var firstname_field = $('#edit-field-profile-first-name-0-value');
  var middlename_field = $('#edit-field-profile-middle-name-0-value');
  var maidenname_field = $('#edit-field-profile-maiden-name-0-value');

  var arr = ['edit-field-profile-last-name-0-value-wrapper', 'edit-field-profile-first-name-0-value-wrapper', 'edit-field-profile-middle-name-0-value-wrapper', 'edit-field-profile-maiden-name-0-value-wrapper'];
	
	// do a foreach if possible on arr
	$.each(arr, function(i, n) {
		/*$(i).blur(function(checkfield) {
			checkNameFields($(this).val());
		});*/
		$('#' + arr[i]).append('<div class="' + arr[i] + ' field-status"></div>');
	});
	
	lastname_field.blur(function() {
		var field = lastname_field;
		checkNameFields(field, $(this).val());
	});
	firstname_field.blur(function() {
		var field = firstname_field;
		checkNameFields(field, $(this).val());
	});
  middlename_field.blur(function() {
    var field = middlename_field;
    checkNameFields(field, $(this).val());
  });
  maidenname_field.blur(function() {
    var field = maidenname_field;
    checkNameFields(field, $(this).val());
  });
	
	
	// the regex
	var checkNameFields = function(field, value) {
		var name_regex = /(^[A-Z]\w+(\s)*)/;
		if(field == lastname_field && !(name_regex.test(value))) {
        $('.edit-field-profile-last-name-0-value-wrapper').text('First letter must be in Upper case, rest in lower case. Example John');
				$('.edit-field-profile-last-name-0-value-wrapper').show();
				//$('#lastname').css({width: "80px", height: "80px", float: "right"});
				return false;
			} else {
				$('.edit-field-profile-last-name-0-value-wrapper').hide();
			}
    if(field == firstname_field && !(name_regex.test(value))) {
        $('.edit-field-profile-first-name-0-value-wrapper').text('First letter must be in Upper case, rest in lower case. Example John');
				$('.edit-field-profile-first-name-0-value-wrapper').show();
				return false;
			} else {
				$('.edit-field-profile-first-name-0-value-wrapper').hide();
			}
    if(field == middlename_field && !(name_regex.test(value))) {
        $('.edit-field-profile-middle-name-0-value-wrapper').text('First letter must be in Upper case, rest in lower case. Example John');
        $('.edit-field-profile-middle-name-0-value-wrapper').show();
        return false;
      } else {
        $('.edit-field-profile-middle-name-0-value-wrapper').hide();
      }
    if(field == maidenname_field && !(name_regex.test(value))) {
        $('.edit-field-profile-maiden-name-0-value-wrapper').text('First letter must be in Upper case, rest in lower case. Example John');
        $('.edit-field-profile-maiden-name-0-value-wrapper').show();
        return false;
      } else {
        $('.edit-field-profile-maiden-name-0-value-wrapper').hide();
      }
			return true;
	}
	
	// student clearance at /student/clearance?jambno
	
	var cleared = 'edit-field-clearance-cleared';
	var not_cleared = 'edit-field-uncleared-wrapper';
	var reasons_uncleared = 'edit-field-uncleared-reasons-wrapper';

  if (document.getElementById('edit-field-uncleared') != null) {
    if (document.getElementById('edit-field-uncleared').checked == false)	$('#' + reasons_uncleared).hide();
  }
	
	var elements_uncleared = [not_cleared, reasons_uncleared];
	var elements_hidden = [not_cleared];

	
	$('#' + cleared, context).bind('click', function(){
		/*$.each(elements_uncleared, function(i, n) {
			$('#' + elements_uncleared[i]).toggle("slow");
		});*/
		//$('#' + cleared).attr("slow");
		// force to be Hidden
		$('#' + reasons_uncleared).hide();
		$('#' + not_cleared).toggle("slow");
		$.each(elements_hidden, function(i, n) {
			if($('#' + elements_hidden[i]).css('display') == 'none'){
				//$('#' + elements_hidden[i] + ' input').setAttribute("checked", "");
				//$('#' + elements_hidden[i] + ' input').removeAttribute("checked");
				//$('#' + elements_hidden[i] + ' input').checked = false;
				//$('#' + elements_hidden[i] + ' input').attr('checked', false);
			}
			//$('#' + elements_hidden[i] + ' input:hidden').attr('checked', '');
		});	
	});
	
	$('#' + not_cleared, context).bind('click', function(){
		//$('#' + not_cleared + ' input').attr("checked", "checked");
		$('#' + reasons_uncleared).toggle("slow");
		//$('#' + cleared).toggle("slow");
	});
	
	// for each element, if anyone is hidden, attr('checked', '')
	//$.each(elements_hidden, function(i, n) {
		/*if($('#' + elements_hidden[i] + 'input').is(":hidden")){
			alert('yes');
			$('#' + elements_hidden[i] + 'input').attr('checked', '');
		}*/
		
			//$('#' + elements_hidden[i]).toggle("slow");
	//});		
	
	var isVisible = function(elem){
		var $elem = $(elem);
		//First check if elem is hidden through css as this is not very costly:
		if($elem.getStyle('display') == 'none' || $elem.getStyle('visibility') == 'hidden' ){
						//elem is set through CSS stylesheet or inline to invisible
						return false;
		}
	}
}

// $.each(Drupal.setting.SelectedRegFormFields).blur(function() {
// perform checkNameFields
//}

