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

// finds the highest y-value of the two points of the roof if "high"==1 and lowest y-value if "high"==0.
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
// finds the x-value corresponding to the highest y-value of the two points of the roof if "high"==1 and x-value corresponding to the lowest y-value if "high"==0.
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

// swaps two lines in the array
void swap(line* arr, int x, int y){
	line temp = arr[y];
	arr[y] = arr[x];
	arr[x] = temp;
}

//sorts the lines according to highest y-value, from lowest to highest
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

//creates a linear regression of a line and then takes the x-value of another line's end point and calculates the y-value for the first line at that x-value
double linear(line* arr, int index, int ekstra){
	double a = (arr[index].left.y-arr[index].right.y) / (arr[index].left.x-arr[index].right.x);
	double b = arr[index].left.y - (a * arr[index].left.x);
	return (a * findHighLowX(arr, ekstra, 1)) + b;
}

//checks if any lines below current line in the line array has an end point higher than the lowest point of the current line. If that is true and the highest point 
//of the line bellow is between the x-coordinates of the current line in the array, it then moves the line below up untill it's above the current line.
void specialSort(line* arr, int n){
	int i, j;
	for(i = n-1; i > 0; i--){
		for(j = i-1; j >= 0; j--){
			if((findHighLowY(arr, j, 1) * 1.0 > linear(arr,i,j)) && ((arr[i].left.x < findHighLowX(arr, j, 1)) && findHighLowX(arr, j, 1) < arr[i].right.x)){
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
	//scans number of roof elements
	scanf("%d", &numberofroofs);
	//allocates memory for waterweight ints
	int* waterweight = (int*)calloc(numberofroofs, sizeof(int));
	//allocates memory for struct line element
	line* roofs = (line*)calloc(numberofroofs, sizeof(line));

	//Init
	if(numberofroofs == 0){
		leftmost = 0;
	}
	//scans input for x and y values for the two points of one roof, it scans n number of roofs, where n is the number of roofs
	for(i = 0; i < numberofroofs; i++) {
		scanf("%d %d %d %d", &roofs[i].left.x, &roofs[i].left.y, &roofs[i].right.x, &roofs[i].right.y);
		if(roofs[i].left.x < leftmost){
			leftmost = roofs[i].left.x;//checks what is the lowest x-value input so we can minimize the size of our arrays
		}
		if(roofs[i].right.x > rightmost){
			rightmost = roofs[i].right.x;//checks what is the highest x-value input so we can minimize the size of arrays.
		}
		roofs[i].weight = &waterweight[i];
	}
	//initializing a piping system that keeps check of how much water there are flowing down from the lower end of a roof and what point the end is at. 
	int piping[rightmost-leftmost][2];
	for (i = 0; i < (rightmost-leftmost); i++){
	    piping[i][0]=i;
	    piping[i][1]=0;
	}
	
	//Sorting
	insertionSort(roofs, numberofroofs);
	specialSort(roofs, numberofroofs);

	//Calculating
	int* rain = (int*)calloc(rightmost-leftmost+1, sizeof(int));//creates and array the keep track of the rain.
	for(i = 0; i < rightmost-leftmost; i++){
		*(rain+i)=1;
	}
	int j;
	for(i = numberofroofs-1; i >=0; i--){//goes through the roof segments one by one, from highest to lowest
		for(j = roofs[i].left.x; j <= roofs[i].right.x; j++){//goes through the horizontal length of the current segment
			if (j != roofs[i].right.x){//makes sure we doesn't count one too far to the right
				*roofs[i].weight += rain[j-leftmost];//adds the weight of the in the current point to the roofs weigt
				rain[j-leftmost] = 0;//sets the rain in the current point to 0 because the roof has blocked it.
			}
			if (roofs[i].right.x != rightmost){//avoids us going out of bounds of our array
			*roofs[i].weight += piping[j-leftmost][1];//adds any water there might fall down from a roof above to the current roofs weight
			piping[j-leftmost][1]=0;//sets the water falling down to 0 because the roof is blocking it
			}
		}
		piping[findHighLowX(roofs, i, 0)-leftmost][1] = *roofs[i].weight;//adds the entire roofs weight to the piping array in the end where the roof is lowest.
	}

	//Printing
	for(i = 0; i < numberofroofs; i++){//prints the weight of the water falling off the different roof segments in the same order tht they were entered.
		printf("%d\n", waterweight[i]);
	}
	return 0;
}
