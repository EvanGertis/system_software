#include <stdio.h>


int main(int argc, char * argv[]){
	int numbers[] = {0,1,2,3,4};
	int *start = numbers;

	for(int i = 0; i < sizeof(numbers)/sizeof(int); i++){
		printf("%d", numbers[i]);
	}
	printf("\n");
	for(int i = 0; i < sizeof(numbers)/sizeof(int); i++){
		printf("%d", *(start + i));
	}
	printf("\n");
	return 0;
}
