#include <pthread.h>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <string>

void *proc(void *arg){
	std::string substring = *(std::string*)arg;
	std::cout << substring << std::endl;
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
	std::string key = "ABCDEFGHIJKLMNOPQRS";
	std::string::iterator it;	
	int i = 0;
	for(it=key.begin(); it != key.end(); it++){
		if(i  % n == 0){
			if( (i+n) < (int)key.capacity()){
				std::string substring;
				substring = key.substr(i,n);
				//std::cout << substring << std::endl;
				r[i] = pthread_create( &id[i], NULL, proc, (void *)&substring);
			}else{
				std::string substring;
				substring = key.substr(i,(key.capacity() - i));
				//std::cout << substring << std::endl;
				r[i] = pthread_create( &id[i], NULL, proc, (void *)&substring);
			}
		}
		i++;
	}		
	
	for(int i=0; i < n; i++){
		pthread_join(id[i], NULL);	
	}

	return 0;
}
