#include <stdio.h>

void swap(int first, int second){
	int temp = first;
	first = second;
	second = temp;
}

int main(int argc, char* argv[]){

	int num1 = 7;
	int num2 = 2;

	swap(num1, num2);
	printf("num1 is %d, num2 is %d\n", num1, num2);
	return 0;
}
