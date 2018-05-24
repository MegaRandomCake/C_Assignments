/*
17. Answer each of the following questions:
a) What is the difference between passing arguments by value and passing arguments by reference?
If you pass an argument by value, then that value will cease to exist when you exit from the fuction and all changes will be discarded.
If you pass an argument by reference (pointer/variable), you can change things in the function, and changes will not be discarded.

b) What values does the rand function generate?
rand(void) is a function that return a pseudo-random number from 0 to at least 32767, based on a seed, like in Slay the Spire.

c) How do you randomize a program? How do you scale or shift the values produced by the rand function?
We can use srand(time(NULL)) to give a seed based on the current time. However we can't change RAND_MAX.
To change the numbers to a certain threeshold, we can use modulus. E.G: rand() % 9 + 10 gives a number from 10 to 19.

d) What is a recursive function?
A function that calls itself. This can go wrong very fast, if you forget to program an exit statement.
E.G all your local variables are located on the stack, while all global/static variables and allocated memory is on the heap.
All we create more variables on the stack, we are going to smash into the heap at some point.
And then... well buckle up, because this is gonna be just like Titanic.
*/
