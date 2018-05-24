#include <stdio.h>
int main()
{
	int a[2][3] = {1, 2, 3, 4, 5}; //All undefined values is init to 0.
	int i = 0, j = 0;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d", a[i][j]);
			return 0;
		}
	}
}

/*
Line 4 is badly written:
int a[2][3] = {
{1,2,3},
{4,5,0}
};

We print all values out in order:
[0][0],[0][1],[0][2],[1][0],[1][1],[1][2]

123450
 */
