#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <cstdlib>
#include <iostream>

void *proc(void *arg)
{

}

struct subString{
	char * buffer;
	int size;
};


int main(int argc, char * argv[]){

	if(argc != 2){
		std::cout << "usage: " << argv[0] << "<int>" << std::endl;
		return 0;
	}

	char randomString[60];
	char alphanum[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 60; ++i) {
        randomString[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

	for(int i=0; i < sizeof(randomString)/sizeof(char); ++i)
		std::cout << randomString[i];
	std::cout << std::endl;
	
	try{
		int n = atoi(argv[1]);
		for(int i=0; i < n; i++){
			for(int j=((sizeof(randomString)/n)*i); j < ((sizeof(randomString)/n)*i + sizeof(randomString)/n); j++)
				std::cout << randomString[j];
			std::cout << std::endl;
		}	
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
