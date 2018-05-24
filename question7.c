#include <stdio.h>

int main(void)
{
	int i;
	int j;
	for(i=20, j=300; i <=j; i+=2, j -= 2){
		printf("%d\n",i+j);
	}
	return 0;
}

/*
i+j will always be 320.
Where i = 162 and j = 158, because when i and j = 160,
we run again for the last time and add 2 to i and subtract 2 from j.

160 160 = true
162 158 = false
 */
