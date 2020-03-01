//This program demonstrates taking the address of a variable and dereferencing a pointer
#include <stdio.h>

int main() {
	float x;
	float *px;//declares a pointer
	
	x = 6.5;
	px = &x;//px is assigned the address of x. That is, px points to x.
	
	printf("The value of x is %f \n", x);
	printf("The value of variable px points to is %f \n", *px);//(*px) dereferences px, i.e, *px is the value of the variable px points to
	printf("The value of px is %p \n", (void*) px); // print the value of px, which is the address of x; %p is a format specification to print pointer values
	printf("The address of x is %p \n", (void*) &x); // print the address of x 

	//modify x through px here
	*px = 4.3;
	printf("The new value of x is %f \n", x);//watch the magic: x's value has been changed!
	return 0;
} // end of main()
