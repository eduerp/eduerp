<?php



function contractor_preq_form(&$obj){
if(!$obj[storage][step])
	$obj[storage][step]=1;
if(!$obj[storage][numc])
$obj[storage][numc]=4;
$form['#title']='Prequalification Form';
if($obj[storage][step]==1){
	
	$form[q]=array('#type'=>'checkbox','#title'=>'Yes I have already paid the required amount before 24 hours','#description'=>'Please confirm you have already paid through bank at least before 24 hours from now.and have the TELLER NUMBER and NAME . <BR/>You will be required to enter this information later and the paid amount must match with the amount payable now. In case you are not able to provide the required information the form won\'t be accepted');
	
	$form[p]=array('#type'=>'fieldset','#description'=>'* Enter the name in textfield and address in textarea below it');
	$form['p'][mark]=array('#value'=> '<b>1. Give details of works which you are handling at present</b><br/>
	<table><tr><th width="15">Value<br/>Of Contract</th><th width="400">Type And Location Of Work</th><th width="15">Percentage<br/>Completed</th>
	<th width="200">Name And Address of <br/>party with Whom contract is made*</th></tr>');

	
$form[p][v1]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>',);
$form[p][w1]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>10,'#prefix'=>'<td>','#suffix'=>'</td>',);

$form[p][p1]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');

$form[p][n1]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>','#description'=>'Name');
$form[p][a1]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>','#description'=>'Address');

$form[p][v2]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p][w2]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][p2]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');

$form[p][n2]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
$form[p][a2]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>');


$form[p][v3]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p][w3]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][p3]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][n3]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
$form[p][a3]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>');

$form[p][v4]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p][w4]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][p4]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][n4]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
///if($obj[storage][numc]==4)
$form[p][a4]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr></table>');

$form[p2]=array('#type'=>'fieldset','#description'=>'* Enter the name in textfield and address in textarea below it');

$form['p2'][mark]=array('#value'=> '<b>2. Give details of major works commenced or completed during the past three years</b><br/>
	<table><tr><th width="15">Value<br/>Of Contract</th><th width="400">Type And Location Of Work</th><th width="15">Percentage<br/>Completed</th>
	<th width="200">Name And Address of <br/>party with Whom contract is made*</th></tr>');

	
$form[p2][v5]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p2][w5]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');

$form[p2][p5]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');

$form[p2][n5]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>','#description'=>'Name');
$form[p2][a5]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>','#description'=>'Address');

$form[p2][v6]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p2][w6]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p2][p6]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');

$form[p2][n6]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
$form[p2][a6]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>');


$form[p2][v7]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p2][w7]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p2][p7]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p2][n7]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
$form[p2][a7]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr></table>',);



//else
//$form[p][a4]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>');


/*
$form[p][v5]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p][w5]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][p5]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][n5]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
$form[p][a5]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>');

$form[p][v6]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p][w6]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][p6]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p][n6]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
$form[p][a6]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<tr><td>','#suffix'=>'</td></tr></table></td></tr></table>');
*/
/*
if($obj[storage][numc]>4){
$c=$obj[storage][numc];
$m=count($form[p])-1;
for($i=5;$i<=$c;$i++){
$form[p]["v$i"]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<tr><td>','#suffix'=>'</td>');
$form[p]["w$i"]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p]["p$i"]=array('#type'=>'textfield' ,'#size'=>10,'#prefix'=>'<td>','#suffix'=>'</td>');
$form[p]["n$i"]=array('#type'=>'textfield','#size'=>25,'#prefix'=>'<td><table><tr><td>','#suffix'=>'</td></tr><tr>');
if($i==$c)
$form[p]["a$i"]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr></table>');
else 
$form[p]["a$i"]=array('#type'=>'textarea' ,'#rows'=>3,'#cols'=>5,'#prefix'=>'<td>','#suffix'=>'</td></tr></table></td></tr>');

}
}*/
//	if(is_array($obj[storage][values][1])){
//	_assign_keys($form,$obj[storage][values][1]);
//	}
$form['#multistep']=true;
$form['#redirect']=false;
$form['submit']=array('#id'=>'edit-next','#type'=>'submit','#value'=>'Next');
///$form['submit2']=array('#id'=>'edit-more','#type'=>'submit','#value'=>'Add More Contracts');


//$form['next']=array('#id'=>'edit-next','#type'=>'submit','#value'=>'Next');
	
}
else if($obj[storage][step]==2) {
		$form['#attributes'] = array('enctype' => "multipart/form-data"); 
	
$form[up]=array('#type'=>'fieldset','#title'=>'Upload Documents');

$form[up][inc]=array('#type'=>'file','#description'=>"incorporation by the Corporate Affairs Commission.");

$form[up][reg]=array('#type'=>'file','#description'=>' Current registration with the Federal Ministry of Works in an appropriate category');
$form[up][tax]=array('#type'=>'file','#description'=>'Tax Clearance Certificate covering last 3 years');
$form[up][acc]=array('#type'=>'file','#description'=>'Last 3 years audited accounts');
$form[up][fin]=array('#type'=>'file','#description'=>' Financial capability');
$form[up][tec]=array('#type'=>'file','#description'=>'Technical capability and list of equipment');
$form[up][vat]=array('#type'=>'file','#description'=>'VAT registration and VAT remittances');
$form[up][bnk]=array('#type'=>'file','#description'=>'Letter of accreditation from bank');

$form[markl]=array('#value'=>'<b>Lot Selection & Fee Total</b>');	
$form[lot]=array('#type'=>'select','#options'=>_contractor_lot(),'#size'=>10,'#multiple'=>true,'#title'=>'Lot Selection','#description'=>' Cost is NGN '.variable_get('veritas_lot_cost','10000').' for each lot selected','#attributes'=>array('style'=>'width:350px;'));

//if(is_array($obj[storage][values][1])){
///	_assign_keys($form,$obj[storage][values][1]);
///	}

$form['#multistep']=true;
$form['#redirect']=false;

$form['submit']=array('#id'=>'edit-previous','#type'=>'submit','#value'=>'Back');
$form['submit2']=array('#id'=>'edit-next','#type'=>'submit','#value'=>'Next');

}
else if($obj[storage][step]==3){
	
$lot=$obj[storage][values][2][lot];
		$amt=count($lot)*variable_get('veritas_lot_cost',10000);
	$form[paynow]=array('#prefix'=>t('Pay Now:'),'#value'=>'NGN&nbsp;'.$amt);

	$form[fees][cpin]=array('#type'=>'textfield','#size'=>25,'#title'=>'TELLER NUMBER','#prefix'=>'<table border="1" align="center"><tr><td><table colspan="2" cellspan="2" align="center"><caption>BANK PAYMENT INFORMATION</caption><tr><th>','#suffix'=>'</th></tr>','#required'=>true );
	$form[fees][cc]=array('#type'=>'textfield','#size'=>25,'#title'=>'NAME','#prefix'=>'<tr><td>','#suffix'=>'</td></tr></table></td></tr></table>','#required'=>true);
	
	//$form[fset][cc]=array('#type'=>'textfield','#size'=>'25','#prefix'=>'<table colspan="2" cellspan="2"><tr><td><b>Card Number:</b></td><td>','#suffix'=>'</td></tr>');
	//$form[fset][cpin]=array('#type'=>'textfield','#size'=>'5','#prefix'=>'<tr><td><b>Card Pin:</b></td><td>','#suffix'=>'</td></tr>');
	
	//$form[fset][edate]=array('#type'=>'ccdt','#prefix'=>'<tr><td><b>Expiry Date:</b></td><td>','#suffix'=>'</td></tr>');
	//	$form[fset][em]=array('#type'=>'select','#options'=>array('01','02','03','04','05','06','07','08','09','10','11','12'),'#prefix'=>'<tr><td><b>Expiry Date</b></th><td>');
	//$form[fset][ey]=array('#type'=>'select','#options'=>array('2008','2009',2010,2011,2012,2013,2014,2015,2016),'#suffix'=>'</td></tr>');
	$form['previous']=array('#id'=>'edit-previous','#submit'=>false,'#type'=>'submit','#value'=>'Back','#prefix'=>'<tr><td>&nbsp;</tr></td><tr><td>','#suffix'=>'</td><td>');
	$form['Make Payment']=array('#id'=>'edit-next','#type'=>'submit','#value'=>'Confirm','#suffix'=>'</td></tr></table>');
	


$form['#multistep'] = TRUE;
$form['#redirect']=false;
	
}




//$form['#validate'][]='contractor_preq_form_submit';
//$form['#submit'][]='contractor_preq_form_submit';

return $form;
}

function contractor_preq_form_validate($form,&$state){
global $user;

$state[storage][values][$state[storage][step]]=$state[values];

	if ($state['clicked_button']['#id']=='edit-previous') {
     $nextstep=   $state['storage']['step']-1;
     return;
    } elseif ($state['clicked_button']['#id']=='edit-next') {
      $nextstep=  $state['storage']['step']+1;
    }
 elseif ($state['clicked_button']['#id']=='edit-more') {
return;
 }
$step=$state[storage][step];
$v=$state[values];
if($nextstep==2){
	if(!$v[q]){
		form_set_error('q',"You must confirm that you have the required payment information.");
		return;
	}
$id=$user->id;
$got=false;
for($i=1;$i<=7;$i++){
if($v["v$i"]){
	if(!is_numeric($v["v$i"]))
	{
		form_set_error("v$i","Invalid contract value");
	}
	if($v["p$i"]>100){
		form_set_error("p$i","Invalid percentage complete value");
		return;
	}
if(!($v["w$i"]&&$v["p$i"]&&$v["n$i"]&&$v["a$i"])){
form_set_error("v$i",'Enter Contract details')	;	
}
	$got=true;
}

}
//if(!$got)
//form_set_error('','Enter Contracts');
}else if($nextstep==3){
if(!count($v[lot])){
	form_set_error('lot','Lots not selected');
	return;
}

	$f1=veritas_check_upload('inc',array(),'',false);
	if($f1){
	form_set_error('inc','Incorporation document cannot be uploaded ');
	}

	$f2=veritas_check_upload('reg',array(),'',false);
	if($f2){
	form_set_error('reg','Registration document cannot be uploaded ');
	}

		$f3=veritas_check_upload('tax',array(),'',false);
	if($f3){
	form_set_error('tax','Tax document cannot be uploaded ');
	}
		$f4=veritas_check_upload('acc',array(),'',false);
	if($f4){
	form_set_error('acc','Audited document cannot be uploaded ');
	}
		$f5=veritas_check_upload('fin',array(),'',false);
	if($f5){
	form_set_error('fin','Financial statements cannot be uploaded ');
	}
		$f6=veritas_check_upload('tec',array(),'',false);
	if($f6){
	form_set_error('tec','Technical documents cannot be uploaded ');
	}
		$f7=veritas_check_upload('vat',array(),'',false);
	if($f7){
	form_set_error('vat','VAT returns cannot be uploaded ');
	}
		$f8=veritas_check_upload('bnk',array(),'',false);
	if($f8){
	form_set_error('bnk','Bank letters cannot be uploaded ');
	}
}else if($nextstep==4){
	$lot=$state[storage][lot];
	
	$amt=count($lot)*variable_get('veritas_lot_cost',10000);
//	$amt=23;
	global $user;
	$state[storage][transid]=$transid=uniqid("w");
	$descr="Prequalification Fees";
$val1=$state['values'];
$em= sprintf("%02d",$val1[edate][em]);
$ey= $val1[edate][ey];

if(!$val1[cc]||!$val1[cpin]){
	form_set_error('','Invalid payment Details');
	return;
}

$s=	veritas_pay_cc($val1[cc],$val1[cpin],$em,$ey,$amt,$descr,$transid,$user->name,$user->mail,'cfee');
if($s>0){
	form_set_error('',"Invalid payment information. ");	
	return;
}
else if($s<0){
	form_set_error('','Transaction processing error. please try later or contact admin');
	return;
	
}
db_query("update transaction set user_type_id=%d where receipt_no='%s'",$user->uid,$transid);

}
	
	
	

}

function contractor_preq_form_submit($form,&$state){
	global $user;
	
$state[storage][values][$state[storage][step]]=$state[values];
 	if ($state['clicked_button']['#id']=='edit-previous') {
        $state['storage']['step']--;
        return;
    } elseif ($state['clicked_button']['#id']=='edit-next') {
        $state['storage']['step']++;
    }
    else if  ($state['clicked_button']['#id']=='edit-more'){
    	if($state[storage][step]==1){
    		if($state[storage][numc]<18)
    	$state[storage][numc]+=2;
    	$state[storage][values][1]=$state[values];
    	}
    	return;
    }
    else exit;
    $step=$state[storage][step];
    $state['rebuild'] = TRUE;	
$transid=$state[storage][transid];
	if($step==2){
		//$state[storage][lot]=$state[values][lot];
		return;
	}
	
else if($step==3){	
	
$v=$state[values];	
$id=$user->uid;


	$f1=file_save_upload('inc',array(),'',false);
	if(!$f1){
		
	drupal_set_message('Incorporation document cannot be uploaded ');
	}

	$f2=file_save_upload('reg',array(),'',false);
	if(!$f2){
	drupal_set_message('Registration document cannot be uploaded ');
		
///	form_set_error('reg','Registration document cannot be uploaded ');
	}

		$f3=file_save_upload('tax',array(),'',false);
	if(!$f3){
		drupal_set_message('Tax document cannot be uploaded ');
///	form_set_error('tax','Tax document cannot be uploaded ');
	}
		$f4=file_save_upload('acc',array(),'',false);
	if(!$f4){
			drupal_set_message();	
		drupal_set_message('Audited document cannot be uploaded ');
///	form_set_error('acc','Audited document cannot be uploaded ');
	}
		$f5=file_save_upload('fin',array(),'',false);
	if(!$f5){
	drupal_set_message('Financial statements cannot be uploaded ');	
//	form_set_error('fin','Financial statements cannot be uploaded ');
	}
		$f6=file_save_upload('tec',array(),'',false);
	if(!$f6){
		drupal_set_message('Technical documents cannot be uploaded ');
///	form_set_error('tec','Technical documents cannot be uploaded ');
	}
		$f7=file_save_upload('vat',array(),'',false);
	if(!$f7){
		drupal_set_message('VAT returns cannot be uploaded ');
///	form_set_error('vat','VAT returns cannot be uploaded ');
	}
		$f8=file_save_upload('bnk',array(),'',false);
	if(!$f8){
		drupal_set_message('Bank letters cannot be uploaded ');
///	form_set_error('bnk','Bank letters cannot be uploaded ');
	}
//$state[storage][step]=2;
$state[storage][lot]=$v[lot];
$state[storage][files]="$f1->fid,$f2->fid,$f3->fid,$f4->fid,$f5->fid,$f6->fid,$f7->fid,$f8->fid";
//db_query("insert into contractor_files set contractor_contractor_id=%d,inc='%s',reg='%s',tax='%s',acc='%s',fin='%s',tec='%s',vat='%s',bnk='%s'",$id,$f1,$f2,$f3,$f4,$f5,$f6,$f7,$f8);	
}
else if($state[storage][step]==4){
$v=$state[storage][values][1];
	
list($f1,$f2,$f3,$f4,$f5,$f6,$f7,$f8)=explode(",",$state[storage][files]);
db_query("insert into contractor_files set contractor_contractor_id=%d,inc='%s',reg='%s',tax='%s',acc='%s',fin='%s',tec='%s',vat='%s',bnk='%s'",$user->uid,$f1,$f2,$f3,$f4,$f5,$f6,$f7,$f8);	
$fs=new stdClass();
for($i=1;$i<=8;$i++){
	$ff="f$i";
$fs->fid=$$ff;
file_set_status($fs,FILE_STATUS_PERMANENT);	
}
for($i=1;$i<=4;$i++){
if($v["v$i"])
db_query("insert into contractor_work set contractor_contractor_id=%d,contract_value='%s',typeandlocation='%s',percentage_complete='%s',contract_party_name='%s',contract_party_address='%s'",$user->uid,$v["v$i"],$v["w$i"],$v["p$i"],$v["n$i"],$v["a$i"]);	
}
for($i=5;$i<=7;$i++){
if($v["v$i"])
db_query("insert into past_contractor_work set contractor_contractor_id=%d,contract_value='%s',typeandlocation='%s',percentage_complete='%s',contract_party_name='%s',contract_party_address='%s'",$user->uid,$v["v$i"],$v["w$i"],$v["p$i"],$v["n$i"],$v["a$i"]);	
}

$lots=$state[storage][lot];
$tid=$state[storage][transid];

foreach($lots as $li)
db_query("insert into contractor_lots set lot_id=%d,contractor_id=%d,trans='%s'",$li,$user->uid,$tid);
unset($state[storage][step]);

 if(variable_get('veritas_logo','')){
 $logourl=url('',array('absolute'=>true)).variable_get('veritas_logo','');
 $img="<img src='$logourl' alt='Veritas Logo'>";
 }else
 $img='';
$r=db_query("select * from transaction where receipt_no='%s'",$tid);
$f=db_fetch_object($r);
veritas_mail_receipt($f,$email,$name,$img);
$rc=db_query("select * from contractor where contractor_id=%d",$user->uid);
$fc=db_fetch_object($rc);


drupal_goto("veritas/receipt/".$f->transaction_id);	
}	


}

function _contractor_lot(){
	static $ritles;
	if(!$titles){
		$r=db_query("select * from lot order by lot_name");
		while($f=db_fetch_object($r))
		$titles[$f->lot_id]=$f->lot_name.':'.$f->description;
	}
	return  $titles;
	
}
?>