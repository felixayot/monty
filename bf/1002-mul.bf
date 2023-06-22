// Read into digits into cells #1 and #2
// Subtract 48 from each: ASCII value for decimal value 0
// Iterate cell #2 while != 0 adding the value of cell #1 to cell #0 every time
>,------------------------------------------------ // Read into #1
>,------------------------------------------------ // Read into #2
[<[>>+<<<+>-]>>[<<+>>-] // Copy #1 into #3 and #0 then copy #3 back to #1
<-] // End loop by decrementing #3 by 1
// Move to #0 and increment by ASCII value 48
<<++++++++++++++++++++++++++++++++++++++++++++++++.
