#include <pthread.h>
#include <iostream>
#include <exception>
#include <string> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include <time.h>

int size = 0;
int M[5][12];

void *proc(void *arg){
	int k = (int)(long)arg;
	for(int i=0; i < 5; i++)
		for(int j = ((12/size)*(k-1)); j < ((12/size)*k); j++)
			M[i][j]= M[i][j]*M[i][j]; 

	pthread_exit(NULL);
}

void printUsage(char * programName){
	printf("usage: %s <int> \n",programName);
}

bool isValidArgument(int n){
	return n >= 2 && n <= 4 ? true : false;
}

void printMatrix(int Matrix[5][12]){
	for(int i=0; i < 5; i++)
		for(int j=0; j < 12; j++)
			j < 11 ? printf("%d ", Matrix[i][j]) : printf("%d \n", Matrix[i][j]);
}

int main(int argc, char * argv[]){
	if(argc != 2){
		printUsage(argv[0]);
		return 0;
	}

	try{
		size = atoi(argv[1]);
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;
	}

	if(!isValidArgument(size)){
		printUsage(argv[0]);
		return 0;
	}

	printf("using: %d threads\n", size);
	
	srand(time(0));
	for(int i=0; i < 5; i++)
		for(int j=0; j < 12; j++)
			M[i][j] = rand() % 49;		
	
	printf("original array: \n");
	printMatrix(M);

	pthread_t id[size];
	for(int j = 1; j < (size+1); j++)
		pthread_create(&id[j], NULL, proc, (void *)(long)j);

	for(int k = 1; k < size+1; k++)
		pthread_join(id[k],NULL);
	
	printf("updated array: \n");
	printMatrix(M);
	
	return 0;
}
