EDUERPTRANSACTION README

This module aims to aggregate the functionality of been able to make payment via ubercart using the
edupay payment system. This is by far incomplete as most of the working features you will find in its
submodules (uc_edupay and us_hostel_allocation).

Included Modules
----------------
1. ajax_eduerptransaction
2. uc_edupay
3. uc_hostel_allocation

ajax_eduerptransaction
----------------------
Enables AJAX functionality for eduerptransaction

uc_edupay
---------
Edupay web service payment system

uc_hostel_allocation
--------------------
Adds a checkout pane to hostel allocation order and also handles all order


Updates to Student module
-------------------------
The eduerptransaction module added new callbacks into the existing Student functionality. Now it is able
to save a reservation before being able to do a checkout. @see student_hostel_reservation().


Updates to Hostel Allocation module
-----------------------------------
The eduerptransaction module introduced new callbacks to provide capability to save reservation as well as
have access to existing saved hostel reservation data.

Example Usage
-------------
Navigate to http://eduerp.datasphir.com/student/hostelreservation, walk through the process of allocation.
Your cart begins at http://eduerp.datasphir.com/student/hostelreservation/cart

API (for developers)
-------------------


TODOs
-----
- Integrate Features to speed up development
- Merge uc_edupay and uc_hostel_allocation into eduerptransaction
- Improve performance of transaction



Kind regards
Kayode Odeyemi
TA, Opevel (http://opevel.com)
