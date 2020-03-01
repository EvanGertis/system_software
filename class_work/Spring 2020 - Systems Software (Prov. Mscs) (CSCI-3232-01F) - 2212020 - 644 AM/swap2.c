//This program demonstrates pointer parameters in function all.
//Change to the value pointed to by the pointer parameter is visible in the caller!
#include <stdio.h>

void swap(int* first, int* second) { // switch around the values of num1 and num2 in main
	int temp;
	temp = *first; //effectively copy num1 to temp
	*first = *second; // effectively copy num2 to num1
	*second = temp; // effectively copy temp to num2
}

int main(void) {
	int num1 = 7; //initial value of num1
	int num2 = 2; //initial value of num2
	printf("before swap, num1 is %d, num2 is %d\n", num1, num2);
	
	int* p1 = &num1;
	int* p2 = &num2;
	swap(p1, p2); // call procedure: still call by value. But num1 and num2 are exchanged through pointers.

	printf("num1 is %d, num2 is %d\n", num1, num2); // what are the values now?

	return 0;
}
