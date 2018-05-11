#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <opencv2/core/core_c.h>

int imagenumber = 0;

void capturing(){
	CvCapture* capture = cvCaptureFromCAM( 0 );
	if( capture )
	{
		FILE *config;
		config = fopen("config.txt", "r");
		FILE *log;
		log = fopen("log2018Maj.txt", "a");
		struct tm *info;
		time_t rawtime;
		char *c_time_string;
		IplImage *current = 0;
		c_time_string = (char*) calloc(25, sizeof(char));
		int i = 0, j = 0;
		int configs[4] = {-1,-1,-1,-1};
		current = cvQueryFrame( capture );
		int w = current->width, h = current->height;
		int change = ((w*h) / 100) / 2;
		IplImage* previous = cvCreateImage(cvSize(w, h), 8, 1);
		IplImage* res = cvCreateImage(cvSize(w, h), 8, 1);
		IplImage* endres = cvCreateImage(cvSize(w, h), 8, 1);
		IplImage* endendres = cvCreateImage(cvSize(w, h), 8, 1);
		CvFont base_font;
		CvScalar color;
		cvInitFont( &base_font, CV_FONT_HERSHEY_SIMPLEX, 1.5, 1.5, 0, 1, 8);

		cvCvtColor(current, res, CV_BGR2GRAY);
		
		while(1)
		{
			current = cvQueryFrame( capture );
			if(!current){
				printf("Stream not found");
				break;
			}
			cvCopy(res, previous, CV_8UC1);
			cvCvtColor(current, res, CV_BGR2GRAY);
			cvAbsDiff(previous, res, endres);
			cvThreshold(endres, endendres, 20, 255, CV_THRESH_BINARY | CV_THRESH_TOZERO);
			if(config){
				color = CV_RGB(0,0,0);
				int configlength = 0;
				fscanf(config, "%d", &configlength);
				for(i = 0; i < configlength * 4; i++){
					fscanf(config, "%d", &configs[j++]);
						if(configs[3] != -1){
							j = 0;
							configs[3] = -1;
							cvRectangle(endendres, cvPoint(configs[0], configs[1]), cvPoint(configs[2], configs[3]), color, CV_FILLED, 8, 0 );
						}
					}
				}
			int m = cvCountNonZero(endendres);
			if(m > change){
				time(&rawtime);
				info = localtime(&rawtime);
				//YYYY-MM-DD hh:mm:ss
				strftime(c_time_string, 20, "%Y-%m-%d %X", info);
				fprintf(log, "%s\n", c_time_string);
				fflush(log);
				imagenumber++;
				int integerlength = floor(log10(abs(imagenumber))) + 1;
				char imagename[10+integerlength];
				snprintf(imagename, sizeof(imagename), "%s%d%s", "image", imagenumber, ".jpg");
				strftime(c_time_string, 25, "%c", info);
				color = CV_RGB(235,235,235);
				cvPutText(current, c_time_string, cvPoint( 10, 50 ), &base_font, color);
				cvSaveImage(imagename, current, 0);
				cvReleaseCapture(&capture);
				break;
				
			}

		}
	}
}

int main(){
	while(1){
	capturing();
	sleep(3);
	}
	return 0;
}
