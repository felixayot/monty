++++++++++  // Set cell #0 to 10
[ // Iterate each cell by #0 value (10)
>+ // Set cell #1 to 1*10=10
>++++++++ // Set cell #2 to 8*10=80
>++++++++++ // Set cell #3 to 10*10=100
>+++++++++++ // Set cell #4 to 11*10=110
<<<<-
] End loop

Results as follows;
Cell #:   0   1   2   3   4
Contents: 0   10  80  100 110

Adjustments then output;

>>+++. // Add 3 to #2 to make it ASCII value 83 to print 'S'
>-. // Subtract 1 from #3 to make it ASCII value 99 to print 'c'
+++++. // Now add 5 to 99 to make it ASCII value 104 to print 'h'
>+..---. // Add 1 to #4 to print 'o' twice then subtract 3 to print 'l'
<<<. // Move back to #1 to print /n
