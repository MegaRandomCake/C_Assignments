/*
2. Identify and correct the errors in each of the following. [Note:There may be more than one
error in each piece of code.]
a)
 */
//int x, total;
//void main1(){
//	int x = 1, product = 0;
//	while ( x <= 10)
//	{
//		product *= x;
//		++x;
//	}
//}
//b)
//void main1(){
//	while( x <= 100)
//		total =+ x;
//	++x;
//}

/*
Errors in a:
While loop does nothing, except make x = 11.
Multiplying with 0 10 times is still 0.

Errors in b:
x and total is undeclared.
No {} for the while, meaning we get stuck in loop if x is under 100.
=+ is equal to = when x is positive.
*/
