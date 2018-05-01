#include <stdio.h>
#include <io.h>
/*

                 \   /
                 .\-/.
             /\  () ()  /\
            /  \ /~-~\ /  \
                y  Y  V
          ,-^-./   |   \,-^-.
         /    {    |    }    \
               \   |   /
               /\  A  /\
              /  \/ \/  \
             /           \
 */
typedef struct {
	int length, linenumber;
} Point;
//Only these should be stuffed into NECKLACE.sol. This is why they are in their own struct.

//These should not.
int curr = 0, prev = 0, NumberX = 0, NumberO = 0,
		NumberATo = 0, NumberATx = 0, MAXIMUM = 0, linecounter = -1, prevLineCounter = 0, switchcounter = 0, totallinecounter = 0;
Point maks;

void TheMagic(){
	linecounter++;

	//Specialtegn
	if(curr == 64){//64@ 120x 111o
		if(prev == 120){
			NumberATx++;
		}
		else{
			NumberATo++;
		}

	}
	else{
		//ligmed hinanden
		if(curr == prev || prev == 0){
			if(curr == 120){
				NumberX++;
			}
			else if(curr == 111){
				NumberO++;
			}
		}
		else{
			//skift
			if(NumberATo + NumberATx + NumberO + NumberX >= MAXIMUM){
				MAXIMUM = NumberATo + NumberATx + NumberO + NumberX;
				maks.length = MAXIMUM;
				maks.linenumber = prevLineCounter;
			}

			if(curr == 120){
				NumberX = 1;
				NumberATx = 0;
			}
			else{
				NumberO = 1;
				NumberATo = 0;
			}
			prevLineCounter = linecounter;
			switchcounter++;
		}

		prev = curr;
	}
}

int main(void) {
	//DO NOT, i repeat DO NOT touch these 3 lines. they took me 45 mins to make.
	char *value = getenv("USERNAME");
	char inputname[36+sizeof(*value)];
	snprintf(inputname, sizeof(inputname), "%s%s%s", "C:\\Users\\", value, "\\Desktop\\NECKLACE.dat");

	FILE *inputfile;
	inputfile = fopen(inputname, "r");

	if(inputfile){

		char outputname[36+sizeof(*value)];
		snprintf(outputname, sizeof(outputname), "%s%s%s", "C:\\Users\\", value, "\\Desktop\\NECKLACE.sol");
		FILE *outputfile;
		outputfile = fopen(outputname, "w"); //w means the file is created. If another file exists with the same name it is deleted.
		totallinecounter = 0;



		while((curr = getc(inputfile)) != EOF){
			fprintf(outputfile, "%c", curr);
			TheMagic();
		}

		fseek(inputfile, 0, SEEK_SET); //Let's read from the beginning
		linecounter = -1;
		switchcounter = 0;

		while(((curr = getc(inputfile)) != EOF) && switchcounter < 2){
			TheMagic();
		}

		fprintf(outputfile,"\n%d between stone %d and stone %d\n", maks.length, maks.linenumber, maks.linenumber+1);

		//Closes the files and opens the .sol file
		fclose(outputfile);
		fclose(inputfile);
		system(outputname);
	}
	//Creates a file and shows it to the user.
	else{
		inputfile = fopen(inputname, "a");
		fprintf(inputfile, "This file have been created on your desktop, to draw a beautiful necklace consisting of 'x', 'o' and '@'."
				"\nPlease make a necklace, save it and restart the application."
				"\nRemember to delete this .dat file and the .sol result file when done with the application.");
		fclose(inputfile);
		system(inputname);
	}

	return 0;
}
