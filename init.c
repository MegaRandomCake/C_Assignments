#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} point;

typedef struct {
	point left;
	point right;
	int* weight;
} line;

int findHighest(line* arr, int index, int high) {
	if(high == 1){
		if(arr[index].left.y < arr[index].right.y) {
			return arr[index].right.y;
		}
		else{
			return arr[index].left.y;
		}
	}
	else{
		if(arr[index].left.y > arr[index].right.y) {
			return arr[index].right.y;
		}
		else{
			return arr[index].left.y;
		}
	}
}

void insertionSort(line* arr, int n)
{
	int i, key, j;
	for (i = n-1; i > 0; i--)
	{
		key = findHighest(arr, i, 1);
		j = i+1;

		while (j <= n && findHighest(arr, j, 1) > key)
		{
			arr[j-1] = arr[j];
			j = j+1;
		}

		if(arr[j-1].left.y < arr[j-1].right.y){
			arr[j-1].right.y = key;
		}
		else{
			arr[j-1].left.y = key;
		}

	}
}
int main(){
	//Variables
	int numberofroofs;
	scanf("%d", &numberofroofs);
	int* waterweight = (int*)calloc(numberofroofs, sizeof(int));
	line* roofs = (line*)calloc(numberofroofs, sizeof(line));

	//Init
	for(int i = 0; i < numberofroofs; i++) {
		scanf("%d %d %d %d", &roofs[i].left.x, &roofs[i].left.y, &roofs[i].right.x, &roofs[i].right.y);
		waterweight[i] = roofs[i].right.x - roofs[i].left.x;
		*roofs[i].weight = waterweight[i];
	}

	//Sorting
	insertionSort(roofs, numberofroofs);

	//Calculating
    for(int i = 0; i < numberofroofs; i++){
    	char* temp = (char*)calloc(roofs[i].right.x - roofs[i].left.x + 1, sizeof(char));
    	for(int j = 0; j < numberofroofs; j++) {
    		if(roofs[i].) {

    		}
    	}
    	free(temp);
    }
	//Printing
	for(int i = 0; i < numberofroofs; i++){
		printf("%d", waterweight[i]);
	}


	return 0;

}
