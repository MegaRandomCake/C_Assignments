/*
4.
Write a single pseudocode statement (or C statement) that indicates each of the following:
a) Display the message "Enter two numbers".
b) Assign the sum of variables x, y, and z to variable p.
c) The following condition is to be tested in an if...elseselection statement: The current
value of variable mis greater than twice the current value of variable v.
d) Obtain values for variables s, r, and t from the keyboard.
 */
	int x,y,z,p,s,r,t, mis = 0, v = 0;

int main(){
	//a
	printf("Enter two numbers");

	p = x + y + z;

	if(mis > v * 2){
		dostuff();
	}
	else{
		dosomeotherstuff();
	}

	printf("%d%d%d", &s, &r, &t);
}
