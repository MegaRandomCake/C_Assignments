#include <stdio.h>
#include <io.h>
//Only these should be stuffed into NECKLACE.sol. This is why they are in their own struct.
typedef struct {
	int length, linenumber;
} Point;

//variables initializiation
int curr = 0, prev = 0, NumberX = 0, NumberO = 0,
		NumberATo = 0, NumberATx = 0, MAXIMUM = 0, linecounter = -1, prevLineCounter = 0, switchcounter = 0, totallinecounter = 0, breaker = 1;
Point maks;

//function for
void TheMagic(){
	linecounter++;

	//Special characters
	if(curr == 64){//64@ 120x 111o
		if(prev == 120){
			NumberATx++;
		}
		else{
			NumberATo++;
		}

	}
	else{
		//if current character == the previous character 
		if(curr == prev || prev == 0){
			//if current is a special character
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
	
	FILE *inputfile;
	inputfile = fopen(NECKLACE.dat, "r");

	if(inputfile){

		FILE *outputfile;
		outputfile = fopen(NECKLACE.sol, "w"); //w means the file is created. If another file exists with the same name it is deleted.
		totallinecounter = 0;

		while(breaker != -1){
			curr = 0, prev = 0, NumberX = 0, NumberO = 0,
					NumberATo = 0, NumberATx = 0, MAXIMUM = 0, linecounter = -1, prevLineCounter = 0, switchcounter = 0;
			fseek(inputfile,totallinecounter, SEEK_SET);

		while((curr = getc(inputfile)) != EOF && curr != 10){
			fprintf(outputfile, "%c", curr);
			TheMagic();
		}
		breaker = curr;
		int temp = ftell(inputfile);
		fseek(inputfile, totallinecounter, SEEK_SET); //Let's read from the beginning
		totallinecounter = temp;
		linecounter = -1;
		switchcounter = 0;
		
		//runs TheMagic() function while current character hasnt reached EOF (End of file) and current character isnt "10"
		while(((curr = getc(inputfile)) != EOF) && curr != 10){
			TheMagic();
		}
		//writes parameter to "outputfile"
		fprintf(outputfile,"\n%d between stone %d and stone %d\n", maks.length, maks.linenumber, maks.linenumber+1);

		}
		//Closes the files and opens the .sol file
		fclose(outputfile);
		fclose(inputfile);
		system(outputname);
	}
	//Creates a file and shows it to the user.
	else{
		inputfile = fopen(NECKLACE.dat, "a");
		//prints to the file "inputfile"
		fprintf(inputfile, "This file have been created on your desktop, to draw a beautiful necklace consisting of 'x', 'o' and '@'."
				"\nPlease make a necklace, save it and restart the application."
				"\nRemember to delete this .dat file and the .sol result file when done with the application.");
		//closes the file
		fclose(inputfile);
		system(inputname);
	}

	return 0;
}
