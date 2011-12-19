Administering Ubercart Fees
---------------------------
- Enable the module at admin/build/modules
- To pay fees, go to user/[user-id]/fees/pay. Updated to student/payfees by Alan
- To views fees summary, go to admin/build/fees

Fixing college filtering on fees summary
----------------------------------------
This leverages uc_eduerp_fees_eduerp_fees_alter to alter fees structure 
in uc_eduerp_fees and then injects college and course (meaning 
fees_structure in which General Fee structure is an item of is no longer 
used to provide filtering for "programme"). In uc_edupay course and 
college are then generated automatically to populate and restructure 
fees_order table.