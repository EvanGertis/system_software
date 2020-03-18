#include <pthread.h>
#include <iostream>
#include <exception>
#include <string> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include <list>
struct args{
	int size;
	char * substring;
};

void *proc(void *arg){
	char substring[((struct args*)arg)->size];
	strcpy(substring,(char *)((struct args*)arg)->substring);
	std::cout << substring << std::endl;
}

void printUsgae(char * programName){
	std::cout << "usage: " << programName << " <int> " << std::endl;
}

bool isValidArgument(int n){
	return n >= 2 && n <= 6 ? true : false;
}

void substring(char source[],char destination[], int position, int length){
	int c = 0;
	while(c < length){
		destination[c] = source[position+c+1];
		c++;	
	}
	source[c] = '\0';
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
	char key[] = "ABCDEFGHIJKLMNOPQRSTUVWYXZABCDEFGHIJKLMNOPQRSTUVWYXZABCDEFGH";
	std::list<int> list;
	int length = (int)sizeof(key)/sizeof(char);
	for(int i = 0; i < length; i++){
		if(i  % n == 0){
			list.push_back(i);
			if( (i+n) < length){
				struct args *arg = (struct args *)malloc(sizeof(struct args));
				char partition[n];
				substring(key,partition,i,n);
				arg->substring = partition;
				arg->size = sizeof(partition);
				pthread_create( &id[i], NULL, proc, (void*)arg);
				std::cout << i << " ";
			}else{
				struct args *arg = (struct args *)malloc(sizeof(struct args));
				char partition[length - i];
				substring(key,partition,i,(length - i));
				arg->substring = partition;
				arg->size = sizeof(partition);
				pthread_create( &id[i], NULL, proc, (void*)arg);
				std::cout << i << " ";
			}
		}	
	}		
	std::cout << std::endl;
	for(int j : list){
		std::cout << j << " ";
		pthread_join(id[j], NULL) == 0 ? printf("thread %d: exited successfully\n", id[j]) : printf("thread %d: did not exit successfully\n", id[j]);	
	}
	std::cout << std::endl;

	return 0;
}
