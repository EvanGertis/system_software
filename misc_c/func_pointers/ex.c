#include <stdio.h>

int add(int num1, int num2){
	return num1 + num2;
}

int main(int argc, char* argv){
	int(*func)(int,int) = &add;
	printf("%d", func(1,1));
	return 0;
}
