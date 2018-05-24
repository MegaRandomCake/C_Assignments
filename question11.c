#include <stdio.h>

void mystery(int *ptra, int *ptrb)
{
	int *temp;
	temp = ptrb;
	ptrb = ptra;
	ptra = temp;
}

int main()
{
	int a=2018, b=0, c=4, d=42;
	mystery(&a, &b);
	if (a < c)
		mystery(&c, &a);
	mystery(&a, &d);
	printf("%d\n", a);
	return 0;
}


/*
Mystery does nothing.
Short answer: C does not allow a user to mess with memory in the sence of swapping memory directly, since 0000 need to come before 0004.
Therefore one should swap the values that are placed on the addresses instead, which can be done by using pointers.

Imagine you have 4 houses on a row. number 1, 3, 5 and 7. Equal to addresses
Smith (3) and Johnson (5) wants to swap houses. Equal to variables.
Instead of swapping the position of the houses, so we have 1, 5, 3 and 7, which is going to fuck up PostNord.
Smith and Johnson swap themselves, so we have 1, Johnson, Smith and 7.

correct way of swapping:
void mystery(int *ptra, int *ptrb)
{
	int temp = *ptra;
	*ptra = *ptrb;
	*ptrb = temp;
}
 */
