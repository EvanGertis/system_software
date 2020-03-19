#include <pthread.h>
#include <iostream>
#include <exception>
#include <string> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>

void *proc(void *arg){
	printf("%d", *(int *)arg);	
	pthread_exit(NULL);
}

void printUsage(char * programName){
	std::cout << "usage: " << programName << " <int> " << std::endl;
}

bool isValidArgument(int n){
	return n >= 2 && n <= 6 ? true : false;
}

char buffer[60];

int main(int argc, char * argv[]){
	int n = 0;

	if(argc != 2){
		printUsage(argv[0]);
		return 0;
	}

	try{
		n = atoi(argv[1]);

	}catch(std::exception e){
		std::cout << e.what() << std::endl;
	}

	if(!isValidArgument(n)){
		printUsage(argv[0]);
		return 0;
	}
	char alphanum[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	pthread_t id[n];
	int * size = &n;
	for (int i = 0; i < 60; ++i) {
		buffer[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	for(int j = 0; j < n; j++){
		pthread_create(&id[j], NULL, proc, (void *)size);
	}
	for(int k = 0; k < n; k++){
		pthread_join(id[k],NULL);
	}
	return 0;
}
