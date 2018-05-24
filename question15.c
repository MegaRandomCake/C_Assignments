struct Course {
	int id;
	char *name;
};
struct Student {
	char *name;
	struct Course courses[3];
};

int main(){
	struct Student student1 = {"Alice"},
			student2 = {"Bob"};
	struct Course course1 = {62409, "C Programming"},
			course2 = {62410, "C++ Programming"},
			course3 = {62411, "Java"};
	student1.courses[0] = course1;
	student1.courses[1] = course2;
	student1.courses[2] = course3;
	student2.courses[0] = course1;
	student2.courses[2] = student1.courses[2];
	printf("%s",student2.courses[2].name);
	return 0;
}

/*
Everything we need is on line 11, 12, 15, 18, 20 and 21. Everything else is filler.
Line 11 and 12: We create Alice and Bob.
Line 15: course3 is Java.
Line 18: Alices course in slot 2 is Java.
Line 20: Bobs course in slot 2 is the same as Alices slot 2 (Java).
Line 21: We print Bobs course in slot 2 (Java).
 */
