#include <stdio.h>

int foo(int a, int b){
	return a + b;
}

int main(int argc, char* argv[]){
	int (*func)(int, int) = &foo;
	int result = func(2,2);
	printf("result: %d \n", result);
	return 0;
}
