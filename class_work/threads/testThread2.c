#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>

void *proc(void *arg)
{
	sleep(2);
	printf("arg=%ld\n", (long)arg);
	//pthread_exit((void *)99);
	return (void *)2016;
}

int main()
{
	int r;
	pthread_t x;
//	void *result;
	r=pthread_create(&x, NULL, proc, (void *)34);
	assert(r==0);
//	assert(pthread_join(x, &result)==0);
//	printf("result=%ld\n", (long)result);
	printf("exiting from main\n");
	pthread_exit(0);//without this statement, thread proc will not print out stuff
	return 0; 
} 
