Dependencies
------------
- views_pdf_mimemail: Sends the mail through mimemail() which has advanced 
support for Gmail and outlook (optional)
- mimemail: A dependency of views_pdf_mimemail (optional)
- views_pdf (upgrade to version 1.0): This upgrades includes a patch for rules 
integration which allows the PDF to be saved as a file which can be downloaded.
- uc_rules: Trigger PDF generation for an order based on the current order id 
when the order state changes to "complete".

Patches
-------
Before enabling the uc_rules module, please apply the patch within the module
file, which basically allows the rule to be evaluated for multiple order
statuses.
