#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <opencv2/core/core_c.h>

int imagenumber = 0;
int numberofcaptures = 1;
FILE *logfil;

void capturing(){
	CvCapture* capture = cvCaptureFromCAM( 0 ); //starts capturing camera footage
	if( capture ) //if camera is capturing
	{
		struct tm *info;
		time_t rawtime;
		char *c_time_string;
		FILE *config;
		config = fopen("config.txt", "r"); //opens file "config"
		IplImage *current = 0; //initialises an image "current"
		c_time_string = (char*) calloc(20, sizeof(char));
		int i = 0, j = 0;
		int configs[4] = {-1,-1,-1,-1};
		current = cvQueryFrame( capture ); //sets current to the current frame from the camera
		int w = current->width, h = current->height;
		int change = ((w*h) / 100) / 2;
		char indexnumber[8] = {"      \n"};
		IplImage* previous = cvCreateImage(cvSize(w, h), 8, 1); //initialises an image "previous"
		IplImage* res = cvCreateImage(cvSize(w, h), 8, 1); //initialises an image "res" (short for result)
		IplImage* endres = cvCreateImage(cvSize(w, h), 8, 1); //initialises an image "endres" (short for endresult)
		IplImage* endendres = cvCreateImage(cvSize(w, h), 8, 1); //initialises an image "endendres" (short for end-endresult)
		CvFont base_font;
		CvScalar color;
		cvInitFont( &base_font, CV_FONT_HERSHEY_SIMPLEX, 1.5, 1.5, 0, 1, 8); //initialises font Hershey Simplex

		cvCvtColor(current, res, CV_BGR2GRAY); //initialises an image "res" (short for result)
		
		while(1)
		{
			current = cvQueryFrame( capture ); //convert current picture to grayscale
			if(!current){
				printf("Stream not found");
				break;
			}
			cvCopy(res, previous, CV_8UC1); //copy res to previous, setting the former frame to previous.
			cvCvtColor(current, res, CV_BGR2GRAY); //convert current picture to grayscale
			cvAbsDiff(previous, res, endres); //find any differing pixels between previous frame and current frame
			cvThreshold(endres, endendres, 20, 255, CV_THRESH_BINARY | CV_THRESH_TOZERO); //set a threshold to limit random noise and small inconsquential changes
			if(config){
				color = CV_RGB(0,0,0); //sets color of black box to, well duh, black
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
			int m = cvCountNonZero(endendres); //set int m to total number of differing pixels in our end result "image"
			if(m > change){
				time(&rawtime); //gets time
				info = localtime(&rawtime);
				//YYYY-MM-DD hh:mm:ss
				strftime(c_time_string, 20, "%Y-%m-%d %X", info); //converts time to string "c_time_string"
				fprintf(logfil, "%s\n", c_time_string); // print current time to log
				fflush(logfil); //flushes logfile from memory, so it isn't open, and therefore isn't read-only
				sprintf(indexnumber, "%d", numberofcaptures++); //writes day to string "indexnumber"
				fseek(logfil, 0, SEEK_SET); 
				fprintf(logfil, "%s\n", indexnumber);  //writes "c_time_string" to string "indexnumber"
				fflush(logfil);
				fseek(logfil, 0, SEEK_END);
				imagenumber++; //advances imagenumber by one for filename purposes
				int integerlength = floor(log10(abs(imagenumber))) + 1; //sets integerlength to count of numeric ciphers in number (e.g. 12 = 2, 2423 = 4, 1543478
= 7				char imagename[10+integerlength]; //sets imagename to length of integerlength, plus 10 characters for other purposes
				snprintf(imagename, sizeof(imagename), "%s%d%s", "image", imagenumber, ".jpg"); //sets size of imagename
				color = CV_RGB(235,235,235);
				cvPutText(current, c_time_string, cvPoint( 10, 50 ), &base_font, color); //hardprint current time and date to picture
				cvSaveImage(imagename, current, 0);
				cvReleaseCapture(&capture);
				break;
				
			}

		}
	}
}

int main(){
	logfil = fopen("log2018Maj.txt", "w");
	fprintf(logfil, "      \n");
	fflush(logfil);
	while(1){
	capturing();
	sleep(3);
	}
	return 0;
}
