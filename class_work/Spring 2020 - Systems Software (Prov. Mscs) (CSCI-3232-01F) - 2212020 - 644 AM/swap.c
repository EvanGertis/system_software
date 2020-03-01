//This program demonstrates "call by value" in function all.
//Recall Java's "call by value" and "call by reference".
#include <stdio.h>

void swap(int first, int second) { // switch the values in first and second
	int temp;
	temp = first; //standard three step switch
	first = second;
	second = temp;
}

int main(void) {
	int num1 = 7; //initial value of num1
	int num2 = 2; //initial value of num2
	printf("before swap, num1 is %d, num2 is %d\n", num1, num2);

	swap(num1, num2); // call procedure: four integers num1, num2, first and second will be on stack

	printf("num1 is %d, num2 is %d\n", num1, num2); // what are the values now? num1 and num2 retain their old values
	return 0;
}
