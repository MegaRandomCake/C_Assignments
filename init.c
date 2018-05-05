#include "opencv2/highgui/highgui.hpp" // required for OpenCV
#include "opencv2/imgproc/imgproc_c.h" // required for OpenCV
#include <stdio.h> // required for printf

int main(int argc, char *argv[]){
	IplImage* image1 = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR); //Loads the image


	if(image1== NULL) {
		printf("Could not open or find the image1\n");
		return -1;
	}
  unsigned int *ptr;
	ptr = (unsigned int*) calloc(256, sizeof(unsigned int)); //Allocates 256 bytes of memory. 1 for each type of gray.
	int w = image1->width;
	int h = image1->height;
	IplImage* res = cvCreateImage(cvSize(w, h), 8, 1);
	cvCvtColor(image1, res, CV_RGB2GRAY);
	int intensities = 0;
  
  //Counts all the pixels.
	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++){
			int k = CV_IMAGE_ELEM(res, unsigned char, i, j); //Returns an integer on the greyscale from pixel x,y.
			*(ptr + k) +=1;
		}
	}
  //Counts the number of different greyscales.
	for(int i = 0; i < 256; i++){
		if(*(ptr + i) != 0){
			intensities++;
		}
	}

	printf("%d\n%dx%d\n", intensities, w, h);
  
  //Prints alle the greyscales out.
	for(int i = 0; i < 256; i++){
			if(*(ptr + i) != 0){
				printf("%d %d\n", i, *(ptr + i));
			}
		}
		return 0;
	}
