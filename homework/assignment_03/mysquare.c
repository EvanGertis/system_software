#include "mysquare.h"

//generate len random integers in the range 0~99
void generateNums(int *myarr, int len){
	printf("generating %d random numbers\n", len);
	for(int i=0; i < len; i++){
		*(myarr+ i) = (rand() % (99 - 0 + 1)) + 0;
	}	
}

//square the len integers stored at myarr
void squareNums(int *myarr, int len){
	printf("squaring %d numbers\n", len);
	for(int i = 0; i < len; i++){
		*(myarr + i) = *(myarr+i) * *(myarr+i);
	}
}

//print the len integers stored at myarr on one line with suitable separators between them
void printNums(int *myarr, int len){
	printf("printing %d numbers\n", len);
	for(int i = 0; i < len; i++){
		printf("%d ", *(myarr + i));
	}
	printf("\n");
}
