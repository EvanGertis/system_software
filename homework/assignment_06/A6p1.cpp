#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include <exception>

void *proc(void *arg){
	int *integer = (int *)arg;
	std::cout << "now printing " << *integer << std::endl;
}

void printUsgae(char * programName){
	std::cout << "usage: " << programName << " <int> " << std::endl;
}

bool isValidArgument(int n){
	return n >= 2 && n <= 6 ? true : false;
}

int main(int argc, char * argv[]){
	int n = 0;

	if(argc != 2){
		printUsgae(argv[0]);
		return 0;
	}

	try{
		n = atoi(argv[1]);

	}catch(std::exception e){
		std::cout << e.what() << std::endl;
	}

	if(!isValidArgument(n)){
		printUsgae(argv[0]);
		return 0;
	}
	
	pthread_t id[n];
	int r[n];

	for(int i=0; i < n; i++){
		int * value = (int *)malloc(sizeof(int));
		*value = i;
		r[i] = pthread_create( &id[i], NULL, proc, (void*) value);
	}
	
	for(int i=0; i < n; i++){
		pthread_join(id[i], NULL);	
	}

	return 0;
}
