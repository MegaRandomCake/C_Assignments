#include <stdio.h>
#include<math.h>

int main(void){
	double Divider = 3; 	//Divisor.
	double Checker = 0;		//Integer that will check what iteration we are on.
	double forrige = 0.0;	//Integer that is compared to i after computing.
	double i = 1.0;			//The integer we need to make pi.

		while(1) {

			forrige = i;

			if(fmod(Checker,2) == 0) { //if we are on an even
				i = i - (1.0/Divider);
			}
			else { //If we are on a odd
				i = i + (1.0/Divider);
			}

			Checker++;
			Divider += 2;

			if((int)(i * 1000000) == (int)(forrige * 1000000)) { //If forrige and i are equal to 6 decimals, i is equal to pi is found and we can print i.
				printf("Pi er fundet efter %d udregninger, hvor den endelige divisor var 1/%d. Pi er sat til %f", (int)Checker, (int)Divider, i*4);
				return 0;
			}

		}

}
