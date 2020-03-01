#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

void *proc(void *arg){
	for(int i=0; i < 5; i++){
		printf("arg=%ld\n", (long)arg);
	}
	pthread_exit((void *)99);
}

int main(int argc, char* argv[]){
	pthread_t x;
	void *result;
	for(int i=0; i < 10; i++){
		pthread_create(&x, NULL, proc, (void*)(rand()%10));
	}
	pthread_join(x, &result);
	printf("result=%ld\n", (long)result);
	return 0;
}
