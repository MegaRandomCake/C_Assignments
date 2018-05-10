#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <opencv2/core/core_c.h>
#define cvmSub( scr1, scr2, dst) cvSub( scr1, scr2, dst, 0)

int main(){
	//FILE *log;
	//log = fopen("test.txt", "w");
	//struct tm *info;
	//time_t rawtime;
	//char *c_time_string;
	IplImage *current = 0;
	//unsigned long m = 0;
	//c_time_string = (char*) calloc(20, sizeof(char));
		CvCapture* capture = cvCaptureFromCAM( 0 );
	if( capture )
	{
		
		current = cvQueryFrame( capture );
		int w = current->width;
		int h = current->height;
		IplImage* previous = cvCreateImage(cvSize(w, h), 8, 1);
		IplImage* res = cvCreateImage(cvSize(w, h), 8, 1);
		IplImage* endres = cvCreateImage(cvSize(w, h), 8, 1);
		IplImage* endendres = cvCreateImage(cvSize(w, h), 8, 1);
		printf("ready\n");

		while(1)
		{
			current = cvQueryFrame( capture );
			if(!current){
				printf("Stream not found");
				break;
			}
			cvCvtColor(res, previous, CV_BGR2GRAY);
			cvCvtColor(current, res, CV_BGR2GRAY);
			//for(int i = 0; i < w; i++){
				//for(int j = 0; j < h; j++){
					//int k = CV_IMAGE_ELEM(res, unsigned char, i, j); //Returns an integer on the greyscale from pixel x,y.
					//int l = CV_IMAGE_ELEM(previous, unsigned char, i, j);
					//if(abs(k-l) != 0){
						//m++;}
				//}
			//}

				//m = (m / (h * w)) * 100;
				
				//if(m >= 0){
				cvAbsDiff(previous, res, endres);
			    cvThreshold(endres, endendres, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
				int m = cvCountNonZero(endendres);
					printf("%i\n", m);
					cvSaveImage("apreviouspic.jpg", previous, 0);
					cvSaveImage("arespic.png", res, 0);
					cvSaveImage("aendrespic.png", endres, 0 );
					cvSaveImage("aendendrespic.png", endendres, 0);
				//time(&rawtime);
				//info = localtime(&rawtime);
				//YYYY-MM-DD hh:mm:ss
				//strftime(c_time_string, 20, "%Y-%m-%d %X", info);
				//fprintf(log, c_time_string);
				//cvCopy(res, previous, CV_8UC1);
				//sleep(5);
			//}
			//m=0;
		}
		cvReleaseCapture(&capture);
	}
	return 0;
}
