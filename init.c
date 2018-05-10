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

int findHighLowY(line* arr, int index, int high) {
	if(high == 1){ //return highest
		if(arr[index].left.y < arr[index].right.y) {
			return arr[index].right.y;
		}
		else{ // return lowest
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

int findHighLowX(line* arr, int index, int high) {
	int x = 0;
	if(high == 1){
		x = 1;
	}
	if(arr[index].left.y == findHighLowY(arr, index, x)){
		return arr[index].left.x;
	}
	else{
		return arr[index].right.x;
	}

}

void swap(line* arr, int x, int y){
	line temp = arr[y];
	arr[y] = arr[x];
	arr[x] = temp;
}

void insertionSort(line* arr, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		j = i;
				while (j > 0 && findHighLowY(arr, j-1, 1) > findHighLowY(arr, j, 1))
				{
					swap(arr, j-1, j);
					j -=1;
				}
	}
}

double linear(line* arr, int index, int ekstra){
	double a = (arr[index].left.y-arr[index].right.y) / (arr[index].left.x-arr[index].right.x);
	double b = arr[index].left.y - (a * arr[index].left.x);
	return (a * findHighLowX(arr, ekstra, 1)) + b;
}

void specialSort(line* arr, int n){
	int i, j;
	for(i = n-1; i >=0; i--){
		for(j = i-1; j > 0; j--){
			if((findHighLowY(arr, j, 1) * 1.0 > linear(arr,i,j)) && ((arr[i].left.x < findHighLowX(arr, j, 1)) && findHighLowX(arr, j, 1) < arr[i].left.x)){
				int position = j;
				while(position < i){
					swap(arr, position, position+1);
					position++;
				}
			}
		}
	}
}

int main(){
	//Variables
	int numberofroofs = 0, leftmost = 2147483647, rightmost = 0, i;
	scanf("%d", &numberofroofs);
	int* waterweight = (int*)calloc(numberofroofs, sizeof(int));
	line* roofs = (line*)calloc(numberofroofs, sizeof(line));

	//Init
	if(numberofroofs == 0){
		leftmost = 0;
	}
	for(i = 0; i < numberofroofs; i++) {
		scanf("%d %d %d %d", &roofs[i].left.x, &roofs[i].left.y, &roofs[i].right.x, &roofs[i].right.y);
		if(roofs[i].left.x < leftmost){
			leftmost = roofs[i].left.x;
		}
		if(roofs[i].right.x > rightmost){
			rightmost = roofs[i].right.x;
		}
		roofs[i].weight = &waterweight[i];
	}

	//Sorting
	insertionSort(roofs, numberofroofs);
	specialSort(roofs, numberofroofs);

	//Calculating
	int* rain = (int*)calloc(rightmost-leftmost+1, sizeof(int));
	for(i = 0; i < rightmost-leftmost; i++){
		*(rain+i)=1;
	}
	int j;
	for(i = numberofroofs-1; i >=0; i--){
		if((rain[roofs[i].left.x] == 1) && (rain[roofs[i].right.x] == 1)){
			*roofs[i].weight -=1;
		}
		for(j = roofs[i].left.x; j <= roofs[i].right.x; j++){
			*roofs[i].weight += rain[j-leftmost];
//			rain[j-leftmost] = 0;
			if (j != roofs[i].right.x){
				rain[j-leftmost] = 0;
			}

		}
		rain[findHighLowX(roofs, i, 0)-leftmost] += *roofs[i].weight;
//		if(roofs[i].left.y < roofs[i].right.y){
//			rain[findHighLowX(roofs, i, 0)-leftmost] +=1;
//		}
	}

	//Printing
	for(i = 0; i < numberofroofs; i++){
		printf("%d\n", waterweight[i]);
	}
	return 0;
}
