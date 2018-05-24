#include <stdio.h>
int main()
{
	int
	t[4]= {10,20,30,40};
	int * ad [4];
	int i;
	for (i=0;i<4;i++)
		ad[i] = t+i; //Set all pointer in ad to point to t.
	for (i=0;i<4;i++)
		printf("%d ", *ad[i]);
	printf("\n");
	printf("%d %d \n", * (ad[1]+1), * ad[1]+1);
	//First print is equal to *ad[1+1]
	//Second print is equal to
	return 0;
}

/*
10 20 30 40
30 21
Note to self:
* means get the thing at the place the pointer is pointing to.
Without *: change the value/address of the pointer.
 */
