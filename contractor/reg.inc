<?php
function contractor_regpay_form($obj){
	$rows=array();
	$v=$obj[storage][values][1];
	$val=$v[value];
	
	$fv=db_query("select * from contractor_fee where contractor_fee_id=$val");
	$fee=db_fetch_object($fv);
	$rows[]=array('Application Fees','NGN '.$fee->application_fee);
	$rows[]=array('Registration Fees','NGN '.$fee->registration_fee);
	$rows[]=array('Total','NGN '.number_format($fee->application_fee+$fee->registration_fee,2));
	
	$table=theme('table',null,$rows,array('width'=>'50%','align'=>'center'),'Payment Details');
	
	

	$form[mark10]=array('#value'=>$table);
	
	$form[fees][cpin]=array('#type'=>'textfield','#size'=>25,'#title'=>'TELLER NUMBER','#prefix'=>'<table border="1" align="center"><tr><td><table colspan="2" cellspan="2" align="center"><caption>BANK PAYMENT INFORMATION</caption><tr><th>','#suffix'=>'</th></tr>','#required'=>true );
	$form[fees][cc]=array('#type'=>'textfield','#size'=>25,'#title'=>'NAME','#prefix'=>'<tr><td>','#suffix'=>'</td></tr></table></td></tr></table>','#required'=>true);
	
	
	//$form[fset]=array('#type'=>'fieldset','#title'=>'Your Credit Card Detail');
	//$form[fset][cc]=array('#type'=>'textfield','#size'=>'25','#prefix'=>'<table colspan="2" cellspan="2"><tr><td><b>Card Number:</b></td><td>','#suffix'=>'</td></tr>');
	//$form[fset][cpin]=array('#type'=>'textfield','#size'=>'5','#prefix'=>'<tr><td><b>Card Pin:</b></td><td>','#suffix'=>'</td></tr>');
	//$form[fset][edate]=array('#type'=>'ccdt','#prefix'=>'<tr><td><b>Expiry Date</td><td>','#suffix'=>'</td></tr>');
	
	//$form[fset][em]=array('#type'=>'select','#options'=>array('01','02','03','04','05','06','07','08','09','10','11','12'),'#prefix'=>'<tr><td><b>Expiry Date:</b></td><td>');
	//$form[fset][ey]=array('#type'=>'select','#options'=>array('2008','2009',2010,2011,2012,2013,2014,2015,2016),'#suffix'=>'</td></tr>');
	
	$form['previous']=array('#id'=>'edit-previous','#type'=>'submit','#value'=>'Back','#prefix'=>'<tr><td>&nbsp;</tr></td><tr><td>','#suffix'=>'</td><td>');
	$form['next']=array('#id'=>'edit-next','#type'=>'submit','#value'=>'Pay Now and register','#suffix'=>'</td></tr></table>');
	return $form;
	//$form[text]=array('#type'=>'textfield');
	//echo drupal_render_form('contract_reg_form',$form);
}
function contractor_form_alter(&$form,$form_state,$form_id){
	if($form_id=='contractor_reg_form'){
if($form[it]){
	$vx=$form_state[values][value];
	if($vx){
	$f=db_query("select * from contractor_fee where contractor_fee_id=%d",$vx);
	$f=db_fetch_object($f);
	$out='<table style="width: 200px;"><caption><b>Fees Payable</b></caption><tr><td><b>Application Fees</b></td><td>NGN '.$f->application_fee.'</td></tr><tr><td><b>Registration Fees</b></td><td>NGN '.$f->registration_fee.'</td></tr><tr><td><b>Renewal Fees</b></td><td>NGN '.$f->renewal_fee.'</td></tr></table>' ;
	
	}
	if(!$out)
	$form['it']=array('#value'=>'<div id="id-fees"><table style="width: 200px;"><caption><b>Fees Payable</b></caption><tbody with="200px"
	<tr><td><b>Application Fees</b></td><td>NGN 1500</td></tr><tr><td><b>Registration Fees</b></td><td></td></tr><tr><td><b>Renewal Fees</b></td><td></td></tr></tbody></table></div>');
	else
	$form['it']=array('#value'=>'<div id="id-fees">'.$out.'</div>');
	
	
}
	
	}
}
function contractor_reg_form(&$obj){
	if(empty($obj[storage][step]))
	$obj[storage][step]=1;
	if($obj[storage][step]==2){
		return contractor_regpay_form($obj);
	}
	//var_dump($obj[storage]);
	$form[q]=array('#type'=>'checkbox','#title'=>'Yes I have already paid the required amount before 24 hours','#description'=>'Please confirm you have already paid through bank at least before 24 hours from now.and have the TELLER NUMBER and NAME . <BR/>You will be required to enter this information later and the paid amount must match with the amount payable now. In case you are not able to provide the required information the form won\'t be accepted');
	
//	$form['ano']=array('#type'=>'textfield','#title'=>'Application Number','#required'=>true,'#maxlength'=>20);
	$form['title']=array('#type'=>'select','#title'=>t('Title'),'#options'=>_veritas_titles(),'#requuired'=>true );
	$form['firstname']=array('#type'=>'textfield','#title'=>'First Name','#size'=>25,'#required'=>true);
	$form['lastname']=array('#type'=>'textfield','#title'=>'Last Name','#size'=>25,'#required'=>true);
	$form['position']=array('#type'=>'select','#title'=>t('Position'),'#options'=>_contractor_position(),'#required'=>true );
	$form['type']=array('#type'=>'select','#title'=>t('Contractor Type'),'#options'=>_contractor_type(),'#required'=>true );
	$form['value']=array('#type'=>'select','#title'=>t('Contractor Value'),	
	'#ahah'=>array('event'=>'change','wrapper'=>'id-fees','path'=>'contractor/fees','method'=>'html'),
	'#required'=>true,'#options'=>_contractor_values() );
	$form['it']=array('#value'=>'<div id="id-fees"><table style="width: 200px;"><caption><b>Fees Payable</b></caption><tbody with="200px"
	<tr><td><b>Application Fees</b></td><td>NGN 1500</td></tr><tr><td><b>Registration Fees</b></td><td></td></tr><tr><td><b>Renewal Fees</b></td><td></td></tr></tbody></table></div>');
	
	$form['compname']=array('#type'=>'textfield','#title'=>'Company Name','#size'=>25,'#required'=>true);
	$form[address]=array('#type'=>'fieldset','#title'=>'Address','#collapsed'=>false,'#collapsible'=>true);
	$form['address'][email]=array('#type'=>'textfield','#title'=>'Email','#size'=>15,'#required'=>true,'#description'=>'Your login details will be sent here');
	$form['address'][city]=array('#type'=>'textfield','#title'=>'City','#size'=>15,'#required'=>true);
	$form['address'][state]=array('#type'=>'select','#title'=>'State','#required'=>true,'#options'=>veritas_states(),'#ahah'=>array('event'=>'change','wrapper'=>'ilga','path'=>'contractor/ajaxlga/state','method'=>'html'),'#default_value'=>'');
	$form['address'][lga]=array('#type'=>'select','#title'=>'Lga','#required'=>true,'#options'=>veritas_lga(),'#prefix'=>'<div id="ilga">','#suffix'=>'</div>','#attributes'=>array('disabled'=>'disabled'),'#default_value'=>'');
	$form[address][address1]=array('#type'=>'textfield','#size'=>25,'#required'=>true,'#title'=>'Address 1');
	$form[address][address2]=array('#type'=>'textfield','#size'=>25 ,'#title'=>'Address 2');
	$form[address][tel1]=array('#type'=>'textfield','#size'=>15,'#required'=>true,'#title'=>'Telephone 1');
	$form[address][tel2]=array('#type'=>'textfield','#size'=>15,'#title'=>'Telephone 2');
	
	$form['business']=array('#type'=>'textfield','#title'=>'Business','#description'=>'Main Area Of Business','#size'=>25,'#required'=>true);
	$form[btype]=array('#type'=>'radios','#options'=>array('C'=>'Company','P'=>'Partnership'),'#title'=>'BUSINESS ORGANIZATION','#default_values'=>'C','#required'=>true);
	$form['lim']=array('#type'=>'fieldset','#title'=>'If application is on behalf of a limited liability company, state the following:','#collapsed'=>false,'#collapsible'=>true);
	$form['lim']['capital']=array('#type'=>'textfield','#title'=>'CAPITAL PAID IN CASH','#size'=>15);
	$form[lim]['dateinc']=array('#type'=>'date','#title'=>'DATE OF INCORPORATION');
	$form['lim']['placeinc']=array('#type'=>'textfield','#title'=>'PLACE OF INCORPORATION','#size'=>25);
	$form[lim]['chairman']=array('#type'=>'textfield','#title'=>'Chairman Name','#size'=>25);
	$form[lim]['vicechairman']=array('#type'=>'textfield','#title'=>'Vice Chairman Name','#size'=>25);
	$form[lim]['treasurer']=array('#type'=>'textfield','#title'=>'Treasurer Name','#size'=>25);
	$form[lim]['secretary']=array('#type'=>'textfield','#title'=>'Secretary Name','#size'=>25);
	$form[lim]['staff_number']=array('#type'=>'textfield','#title'=>'Number Of Staff','#size'=>7);
	
	$form['part']=array('#type'=>'fieldset','#title'=>'If application is on behalf of a partnership, state','#collapsed'=>false,'#collapsible'=>true);
	$form['part']['datereg']=array('#type'=>'date','#title'=>'Date of Registration');
	$form['part']['placereg']=array('#type'=>'textfield','#title'=>'Place Of Registration','#size'=>25);
	$form['part'][mark]=array('#value'=>'<br/><b>Give particulars of Partners as below:</b>');
	$form['part'][mark2]=array('#value'=>'<table><tr><th>Name</th><th>Address</th><th>Age</th></tr>');
	$form['part'][p_1]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form['part'][padd_1]=array('#type'=>'textfield','#size'=>35,'#prefix'=>'<td>','#suffix'=>'</td>');
	$form['part'][page_1]=array('#type'=>'textfield','#size'=>6,'#prefix'=>'<td>','#suffix'=>'</td></tr>');
	$form['part'][p_2]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form['part'][padd_2]=array('#type'=>'textfield','#size'=>35,'#prefix'=>'<td>','#suffix'=>'</td>');
	$form['part'][page_2]=array('#type'=>'textfield','#size'=>6,'#prefix'=>'<td>','#suffix'=>'</td></tr>');
	$form['part'][p_3]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form['part'][padd_3]=array('#type'=>'textfield','#size'=>35,'#prefix'=>'<td>','#suffix'=>'</td>');
	$form['part'][page_3]=array('#type'=>'textfield','#size'=>6,'#prefix'=>'<td>','#suffix'=>'</td></tr></table>');
	
	$form[pexp]=array('#type'=>'fieldset','#collapsible'=>true);
	$form[pexp]['regmark']=array('#value'=>'<br/><b>State any previous application(s) that have been made to be registered as a contractor with any government body or other organisation Nigeria:</b>');
	$form[pexp][mark3]=array('#value'=>'<table><tr><th>NAME OF GOVERNMENT & OTHER ORGANISATIONS</th><th>Date</th><th>Whether Approved</th><th>Registration Number</th></tr>');
	$form[pexp][govorg1]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[pexp][govdate1]=array('#type'=>'date','#prefix'=>'<td>','#suffix'=>'</td>');
	$form[pexp][govapp1]=array('#type'=>'radios','#prefix'=>'<td>','#suffix'=>'</td>','#options'=>array('Yes'=>'Yes','No'=>'No'),'#default_value'=>'No');
	$form[pexp][govreg1]=array('#type'=>'textfield','#size'=>15,'#prefix'=>'<td>','#suffix'=>'</td></tr>');

	$form[pexp][govorg2]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[pexp][govdate2]=array('#type'=>'date','#prefix'=>'<td>','#suffix'=>'</td>');
	$form[pexp][govapp2]=array('#type'=>'radios','#prefix'=>'<td>','#suffix'=>'</td>','#options'=>array('Yes'=>'Yes','No'=>'No'),'#default_value'=>'No');
	$form[pexp][govreg2]=array('#type'=>'textfield','#size'=>15,'#prefix'=>'<td>','#suffix'=>'</td></tr>');
	$form[pexp][govorg3]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[pexp][govdate3]=array('#type'=>'date','#prefix'=>'<td>','#suffix'=>'</td>');
	$form[pexp][govapp3]=array('#type'=>'radios','#prefix'=>'<td>','#suffix'=>'</td>','#options'=>array('Yes'=>'Yes','No'=>'No'),'#default_value'=>'No');
	$form[pexp][govreg3]=array('#type'=>'textfield','#size'=>15,'#prefix'=>'<td>','#suffix'=>'</td></tr></table>');
	
	$form[exp]=array('#type'=>'fieldset','#collapsible'=>true,'#collapsed'=>false);
	$form[exp][mark4]=array('#value'=>'<br/><b>State the years of experience as contractor and sub-contractor. If the organisation has changed its name at any time the previous name should be given.</b>');
	$form[exp][mark5]=array('#value'=>'<table bordercolor="000000" border="1"><tr><th>NAME(S) OF ORGANISATION</th><th width="349" colspan="3">PERIOD DURING WHICH USED</th><th width="50">YEARS</th></tr><tr><td></td><td width="107">From</td><td width="100">To</td><td width="114">Contractor</td><td></td></tr>');
	$form[exp][orgname1]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[exp][p_from1]=array('#type'=>'date','#prefix'=>'<td width="107">','#suffix'=>'</td>');
	$form[exp][p_to1]=array('#type'=>'date','#prefix'=>'<td width="100">','#suffix'=>'</td>');
	$form[exp][p_name1]=array('#type'=>'textfield','#size'=>20,'#prefix'=>'<td width="114">','#suffix'=>'</td>');
	$form[exp][p_years1]=array('#type'=>'textfield','#size'=>5,'#prefix'=>'<td width="105">','#suffix'=>'</td></tr>');
	
	$form[exp][orgname2]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[exp][p_from2]=array('#type'=>'date','#prefix'=>'<td width="107">','#suffix'=>'</td>');
	$form[exp][p_to2]=array('#type'=>'date','#prefix'=>'<td width="100">','#suffix'=>'</td>');
	$form[exp][p_name2]=array('#type'=>'textfield','#size'=>20,'#prefix'=>'<td width="114">','#suffix'=>'</td>');
	$form[exp][p_years2]=array('#type'=>'textfield','#size'=>5,'#prefix'=>'<td width="105">','#suffix'=>'</td></tr>');
	
	$form[exp][orgname3]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[exp][p_from3]=array('#type'=>'date','#prefix'=>'<td width="107">','#suffix'=>'</td>');
	$form[exp][p_to3]=array('#type'=>'date','#prefix'=>'<td width="100">','#suffix'=>'</td>');
	$form[exp][p_name3]=array('#type'=>'textfield','#size'=>20,'#prefix'=>'<td width="114">','#suffix'=>'</td>');
	$form[exp][p_years3]=array('#type'=>'textfield','#size'=>5,'#prefix'=>'<td width="105">','#suffix'=>'</td></tr></table>');
	
	$form[tech]=array('#type'=>'fieldset','#collapsible'=>true,'#collapsed'=>false);
	$form[tech][mark5]=array('#value'=>'<b>Give details of the technical qualification of main staff</b>');
	$form[tech][mark6]=array('#value'=>'<table border="1" bordercolor="000000"><tr><th>Name</th><th>Position In Organisation</th><th>Qualification</th></tr>');
	$form[tech][sname1]=array('#type'=>'textfield','#size'=>20,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[tech][spos1]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td>','#suffix'=>'</td>');
	$form[tech][sq1]=array('#type'=>'textfield','#size'=>15,'#prefix'=>'<td>','#suffix'=>'</td></tr>');
	$form[tech][sname2]=array('#type'=>'textfield','#size'=>20,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[tech][spos2]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td>','#suffix'=>'</td>');
	$form[tech][sq2]=array('#type'=>'textfield','#size'=>15,'#prefix'=>'<td>','#suffix'=>'</td></tr>');
	$form[tech][sname3]=array('#type'=>'textfield','#size'=>20,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
	$form[tech][spos3]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td>','#suffix'=>'</td>');
	$form[tech][sq3]=array('#type'=>'textfield','#size'=>15,'#prefix'=>'<td>','#suffix'=>'</td></tr></table>');
	
	$form[mark7]=array('#value'=>'<ul>
	<li><p style="margin-bottom: 0in; line-height: 150%;" class="western">
	<b>All information given will be treated in confidence by Veritas
	University.</b></p>
	</li><li><p style="margin-bottom: 0in; line-height: 150%;" class="western">
	 <b>Incomplete Application Forms will not be considered.</b></p>
	</li><li><p style="margin-bottom: 0in; line-height: 150%;" class="western">
	<b>Application Forms containing false information will be
	automatically disqualified.</b></p>
</li></ul><br/>');
	$form['dec']=array('#type'=>'checkbox','#title'=>'Agree','#prefix'=>'<p>DECLARATION:
<font color="#1f497d"></font> I, hereby declare that all
the information given in this form is, to the best of my knowledge
and belief, correct. Any false information given in this form will
automatically disqualify me from being consideration as a contractor</p>');
	 //if(is_array($obj[storage][values][1])){
	//_assign_keys($form,$obj[storage][values][1]);
    //}
	
	$form['next']=array('#id'=>'edit-next','#type'=>'submit','#value'=>'Next');
//$form['#rebuild']=true;
$form['#multistep']=true;
	//$form['part'][]
	return $form;
}

function contractor_get_reg1(){
	return drupal_get_form('contractor_reg_form');
}

function _contractor_values(){
	static $ritles;
	if(!$titles){
		$titles[]='';
		$r=db_query("select * from contractor_fee order by contractor_fee_id");
		while($f=db_fetch_object($r))
		$titles[$f->contractor_fee_id]=$f->description;
	}
	return  $titles;

}

function _contractor_type(){
	static $ritles;
	if(!$titles){
		$r=db_query("select * from contractor_type order by contractor_type_name");
		while($f=db_fetch_object($r))
		$titles[$f->contractor_type_id]=$f->contractor_type_name;
	}
	return  $titles;

}
function _contractor_position(){
	static $ritles;
	if(!$titles){
		$r=db_query("select * from contractor_position order by position_name");
		while($f=db_fetch_object($r))
		$titles[$f->position_id]=$f->position_name;
	}
	return  $titles;

}

function contractor_reg_form_validate($form,&$state){
$state['storage']['values'][$state['storage']['step']] = $state['values'];
	
	$val=$state['values'];
	if ($state['clicked_button']['#id']=='edit-previous') {
     $nextstep=   $state['storage']['step']-1;
     return;
    } elseif ($state['clicked_button']['#id']=='edit-next') {
      $nextstep=  $state['storage']['step']+1;
    }
	$step=$state[storage][step];
	
	if($val)
	if($nextstep==2){
	if(!$val[q]){
		form_set_error("You must confirm that you have the required payment information.");
		return;
	}
		
		
		if(!$val[dec])
		form_set_error('dec',t('You need to agree to the terms'));
	else if(!$val[value]||!is_numeric($val[value]))
		form_set_error('value',t('Invalid contract value'));
	else if(!veritas_validuser($val[email],$val[email])){
		return false;
	}	
	if(!$val[state]||!$val[lga]){
		form_set_error('state','State and lga required');
		return false;
	}
		if($val[btype]=='C'){
		if(!($val[capital]&&$val[placeinc]&&$val[chairman]&&$val[vicechairman]&&$val[treasurer]&&$val[secretary]&&$val[staff_number])){
form_set_error('lim','You need to enter all the company details fields');		

		}
		}else if($val[btype]=='P'){
if(!($val[p_1]||$val[p_2]||$val[p_3]))
{
	form_set_error('p_1','Enter partner Details');
	return;
}

			
			if(!$val[placereg])
			form_set_error('placereg','Enter Place of Registration');
			if($val[p_1]&&(!$val[page_1]||!$val[padd_1])){
			form_set_error('p_1','Enter partner Details');
				return false;
			}
			if($val[p_2]&&(!$val[page_2]||!$val[padd_2])){
				form_set_error('p_2','Enter partner Details');
				return false;
			}
				if($val[p_3]&&(!$val[page_3]||!$val[padd_3])){
				form_set_error('p_3','Enter partner Details');
					return false;
			}
		
			
			
		}//p
		
		if($val[govorg1]&&!$val[govreg1]){
				form_set_error('govreg1','Enter registration number');
		}
		if($val[govorg2]&&!$val[govreg2]){
				form_set_error('govreg2','Enter registration number');
		}
				if($val[govorg3]&&!$val[govreg3]){
				form_set_error('govreg3','Enter registration number');
		}
if($val[sname1]&&(!$val[spos1]||!$val[sq1]))	
form_set_error('sname1','Enter staff detail');
if($val[sname2]&&(!$val[spos2]||!$val[sq2]))	
form_set_error('sname2','Enter staff detail');
if($val[sname3]&&(!$val[spos3]||!$val[sq3]))	
form_set_error('sname3','Enter staff detail');


	
	}
		
	else if($nextstep==1){
	}
	else if($nextstep==3){
		$descr="Contractor Registration Fees";
		$transid=uniqid('c_');
	$vs=(int)$state[storage][values][1][value];
	$name=check_plain($state[storage][values][1][business]);
	$email=$state[storage][values][1][email];
	$type=$state[storage][values][1][type];
	
	
	if(!$vs){
		form_set_error('value','contract value missing');
		return;
	}
	$fv=db_query("select * from contractor_fee where contractor_fee_id=$vs");
	$fee=db_fetch_object($fv);
	$amt=$fee->application_fee+$fee->registration_fee;
	if(!$amt){
		form_set_error('',"Invalid form amount submission.");	
		return;
	}
$val1=$state['values'];
$em= sprintf("%02d",$val1[edate][em]);
$ey=$val1[edate][ey];
$name=$state[storage][values][1][compname];
if(!$val1[cc]||!$val1[cpin]){
	form_set_error('','Invalid Payment Details');
	return;
}

$s=	veritas_pay_cc($val1[cc],$val1[cpin],$em,$ey,$amt,$descr,$transid,$name,$email,'creg');
if($s>0){
		form_set_error('',"Invalid payment information. ");	
	return;
}
else if($s<0){
	form_set_error('','Transaction processing error. please try later or contact admin');
	return;
	
}
///$_SESSION[transid]=$transid;
///	contractor_reg_form_submit($form,&$state);
	}
$state[storage][values][transid]=$transid;
	

}
function contractor_reg_form_submit($form,&$state){
	global $user;
	
 	if ($state['clicked_button']['#id']=='edit-previous') {
///$state['storage']['values'][$state['storage']['step']] = $state['values'];
 		
 		$state['storage']['step']--;
 		return;
    } elseif ($state['clicked_button']['#id']=='edit-next') {
        $state['storage']['values'][$state['storage']['step']] = $state['values'];
    	
    	$state['storage']['step']++;
    }else
    return;
    $step=$state[storage][step];
$transid=$state[storage][values][transid];

	if($step==1){
		}
	else if($step==2){

	}
	else{

    $state['rebuild'] = TRUE;	
		
	$val=$state[storage][values][1];;
		if(!$transid){
			echo "invalid transaction";
			exit;
		}
		$type='creg';
		$acc=veritas_user_save($type,$val[email],$transid);
$uid=$acc->uid;
if($uid){
contractor_add($uid,$val);	
$t=db_query("select * from transaction where receipt_no='%s'",$transid);
$f=db_fetch_object($t);
	drupal_goto('veritas/receipt/'.$f->transaction_id);
}else{
	drupal_set_message('Registration cannot be done . please contract admin');
		drupal_goto('veritas/error');
	
}
	
	}
}
function contractor_add($id,&$val){
	$val[dateinc_v]=$val[dateinc][year].'-'.$val[dateinc][month].'-'.$val[dateinc][day];
	$val[regdate_v]=$val[datereg][year].'-'.$val[datereg][month].'-'.$val[datereg][day];
	$val[govdate1_v]=$val[govdate1][year].'-'.$val[govdate1][month].'-'.$val[govdate1][day];
	$val[govdate2_v]=$val[govdate2][year].'-'.$val[govdate2][month].'-'.$val[govdate2][day];
	$val[govdate3_v]=$val[govdate3][year].'-'.$val[govdate3][month].'-'.$val[govdate3][day];
	
	$val[p_from1_v]=$val[p_from1][year].'-'.$val[p_from1][month].'-'.$val[p_from1][day];
	$val[p_from2_v]=$val[p_from2][year].'-'.$val[p_from2][month].'-'.$val[p_from2][day];
	$val[p_from3_v]=$val[p_from3][year].'-'.$val[p_from3][month].'-'.$val[p_from3][day];
	
	$val[p_to1_v]=$val[p_to1][year].'-'.$val[p_to1][month].'-'.$val[p_to1][day];
	$val[p_to2_v]=$val[p_to2][year].'-'.$val[p_to2][month].'-'.$val[p_to2][day];
	$val[p_to3_v]=$val[p_to3][year].'-'.$val[p_to3][month].'-'.$val[p_to3][day];
	
	db_query("insert into contact set contractor_contractor_id='%s',title='%s',first_name='%s',middle_name='%s',last_name='%s',position='%s',ano='%s'",$id,$val[title],$val[firstname],$val[middlename],$val[lastname],$val[position],$val[ano]);
	
	db_query("insert into contractor set contractor_id=%d,user_type_id='%s',companyname='%s',address1='%s',address2='%s',city='%s',
	lga='%s',state='%s',telephone='%s',gsm='%s',email='%s',
	mainbusiness='%s',capital='%s',dateinc='%s',placeinc='%s',chairmanname='%s',
	vicechairmanname='%s',treasurername='%s',staff_number=%d,secretaryname='%s'",$id,$id,$val[compname],$val[address1],
	$val[address2],$val[city],$val[lga],$val[state],$val[tel1],$val[tel2],$val[email],
	$val[business],$val[capital],$val[dateinc_v],$val[placeinc],$val[chairman],$val[vicechairman],$val[treasurer],$val[staff_number],
	$val[secretary]);
	//$id=$uid;///db_last_insert_id('contractor','contractor_id');
	if($val[btype]=='P'){
	db_query("insert into partnership set contractor_contractor_id=%d,partnership_name='%s',registration_date='%s',placereg='%s',
partner_1='%s',partner_2='%s',partner_3='%s',
age_1='%s',age_2='%s',age_3='%s',
address_1='%s',address_2='%s',address_3='%s'
",$id,$val[compname],$val[regdate_v],$val[placereg],
	$val['p_1'],$val[p_2],$val[p_3],
	$val[page_1],$val[page_2],$val[page_3],
	$val[padd_1],$val[padd_2],$val[p_add3]

	);
	}
	if($val[govorg1]){
db_query("insert into registered_contractor_detail set contractor_contractor_id=%d,govt_organisation='%s',g_date='%s',approved='%s',
registration_number='%s'",
$id,$val[govorg1],$val[govdate1_v],$val[govapp1],$val[govreg1]);
	}
	if($val[govorg2]){
db_query("insert into registered_contractor_detail set contractor_contractor_id=%d,govt_organisation='%s',g_date='%s',approved='%s',
registration_number='%s'",
$id,$val[govorg2],$val[govdate2_v],$val[govapp2],$val[govreg2]);
	}
	
	if($val[govorg3]){
db_query("insert into registered_contractor_detail set contractor_contractor_id=%d,govt_organisation='%s',g_date='%s',approved='%s',
registration_number='%s'",
$id,$val[govorg3],$val[govdate3_v],$val[govapp3],$val[govreg3]);
	}
	if($val[orgname1]){
db_query("insert into contractor_experience set contractor_contractor_id=%d,organisation_name='%s',period_from='%s',
period_to='%s',previous_name='%s',years='%s'",$id,
$val[orgname1],$val[p_from1_v],$val[p_to1_v],$val[p_name1],$val[p_years1]);
		
	}
	
	if($val[orgname2]){
db_query("insert into contractor_experience set contractor_contractor_id=%d,organisation_name='%s',period_from='%s',
period_to='%s',previous_name='%s',years='%s'",$id,
$val[orgname2],$val[p_from2_v],$val[p_to2_v],$val[p_name2],$val[p_years2]);
		
	}
	
	if($val[orgname3]){
db_query("insert into contractor_experience set contractor_contractor_id=%d,organisation_name='%s',period_from='%s',
period_to='%s',previous_name='%s',years='%s'",$id,
$val[orgname3],$val[p_from3_v],$val[p_to3_v],$val[p_name3],$val[p_years3]);
	}
	
if($val[sname1]){
	db_query("insert into contractor_tech_staff set contractor_contractor_id='%d',name='%s',position='%s',qualification='%s'",
	$id,$val[sname1],$val[spos1],$val[sq1]);
}
if($val[sname2]){
	db_query("insert into contractor_tech_staff set contractor_contractor_id='%d',name='%s',position='%s',qualification='%s'",
	$id,$val[sname2],$val[spos2],$val[sq2]);
}
if($val[sname3]){
	db_query("insert into contractor_tech_staff set contractor_contractor_id='%d',name='%s',position='%s',qualification='%s'",
	$id,$val[sname3],$val[spos3],$val[sq3]);
}
	
}
?>