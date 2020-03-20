#include <pthread.h>
#include <iostream>
#include <exception>
#include <string> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>

char buffer[60];
int size = 0;

void *proc(void *arg){
	long j = (long)arg;
	//printf("%d\n", j);
	//printf("start: %d\n", (int)((60/size)*(j-1)));
	//printf("end: %d\n",  (int)((60/size)*j));
	for(int i = ((60/size)*(j-1)); i < ((60/size)*j); i++){
		printf("%c", (buffer[i] - 'a'));
		buffer[i]= std::tolower((buffer[i] - 'a'));
	}
	printf("\n");
	pthread_exit(NULL);
}

void printUsage(char * programName){
	std::cout << "usage: " << programName << " <int> " << std::endl;
}

bool isValidArgument(int n){
	return n >= 2 && n <= 6 ? true : false;
}

int main(int argc, char * argv[]){
	if(argc != 2){
		printUsage(argv[0]);
		return 0;
	}

	try{
		size = atoi(argv[1]);

	}catch(std::exception e){
		std::cout << e.what() << std::endl;
	}

	if(!isValidArgument(size)){
		printUsage(argv[0]);
		return 0;
	}


	char alphanum[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";	
	for (int i = 0; i < 60; i++)
		buffer[i] = alphanum[rand() % (sizeof(alphanum) - 1)];

	printf("original upper case string: %s\n", buffer);

	pthread_t id[size];
	for(int j = 1; j < (size+1); j++)
		pthread_create(&id[j], NULL, proc, (void *)(long)j);

	for(int k = 1; k < size+1; k++)
		pthread_join(id[k],NULL);
	
	printf("complementary lower case string:: %s\n", buffer);
	
	return 0;
}
