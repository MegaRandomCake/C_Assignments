#include <stdio.h>
#include<math.h>
#include <stdbool.h>



void GoldbachFunction(int i){
	const int CompilerErrorGoAway = i; //C do NOT like making a array with length of variable. This for some reason makes the error go away. Buuut we should probably fix it some other way
	bool PrimeChecker[CompilerErrorGoAway + 1];
	for(int j = 0; j < i; j++){
		PrimeChecker[j] = true;
	}
	int prime[CompilerErrorGoAway/2 + 2];
	int inserter = 0;

	for(int j = 2; j <= i; j++){
		if(PrimeChecker[j] == true){
			prime[inserter] = j;
			inserter++;
			for(int k = 2*j; k <= i; k +=j){
				PrimeChecker[k] = false;
			}
		}
	}
	inserter = 0;
	printf("Alle naturlige tal mindre end første input der ikke er en værdi af 2 primtal:\n");

	for(int j = 1; j < i; j++){

		if(fmod(j, 2) == 0 && (j != 4 && j != 2)){

		}

		else if(prime[inserter] + 2 != j){
			printf("%d ", j);
		}

		else{
			inserter++;
		}

	}
	printf("\n");
	return;

	//Note to self. 0 er/er ikke et naturligt nummer baseret på hvem man spørger. Her er 0 ikke taget som et naturligt nummer
}

int main(void){
	double LigeTotal = 0;  //Sum of all even numbers entered.
	double UligeTotal = 0; //Sum of all odd numbers entered.
	int LigeAntal = 0;     //Amount of the even numbers entered. zero excluded.
	int UligeAntal = 0;	   //Amount of odd number entered.
	int input = 0;		   //Whatever the user inputs.
	int antidivisor1 = 0;  //Countermeasure to not divide by 0, if 0 is the first input.
	int antidivisor2 = 0;  //Countermeasure to not divide by 0, if 0 is the first input.

	scanf(" %d", &input);
	GoldbachFunction(input);

	while(input != 0){
		if(fmod(input,2) == 0) {
			LigeTotal = LigeTotal + input;
			LigeAntal++;
		}
		else {
			UligeTotal = UligeTotal + input;
			UligeAntal++;
		}

		scanf(" %d", &input);
	}

	//If zero is entered before a odd or even number, these are run to avoid division by zero. Because division by zero is bad, like it will probably break mathematics or something.
	if(LigeAntal == 0)
		antidivisor1++;
	if(UligeAntal == 0)
		antidivisor2++;


	printf("Der blev scannet %i lige integers, der havde en gennensnitsværdi på %.2f,\n"
			"og der blev scannet %i ulige integers, der havde en gennensnitsværdi på %.2f",
			LigeAntal, LigeTotal/(LigeAntal+antidivisor1), UligeAntal, UligeTotal/(UligeAntal+antidivisor2));

	return 0;
}
