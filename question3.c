/*
3. What does the following program print:

1 #include<stdio.h>
2
3 intmain( void)
4 {
5   int y;
6   int x = 1;
7   int total = 0;
8
9   while( x <= 5) {
10     y = x * x * x;
11     printf( "%d\n", y );
12     total += y;
13     ++x;
14  }//end while
15
16 printf( "The total is %d\n", total );
17 }// end main


Technical we would get an error since intmain is wrong, however if that is fixed:
1
8
27
64
125
The total is 225
 */
