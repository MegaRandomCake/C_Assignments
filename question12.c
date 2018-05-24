/*
If a variable has to store the address of the address of a character, what must be the type of its definition?

Short answer char**.

Long answer: If we have the code from question 11, and modify it so work with chars instead, so we can swap pointers.
 */

#include <stdio.h>

void mystery(char **ptra, char **ptrb)
{
	char *temp = *ptrb;
	*ptrb = *ptra;
	*ptra = temp;
}

int main()
{
	char *a="abc", *b="def";
	mystery(&a, &b);
	printf("%s\n", a);
	return 0;
}
