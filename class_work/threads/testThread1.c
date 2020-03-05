#include <stdio.h>
#include <pthread.h>
#include <assert.h>

void *proc(void *arg)
{
	int i;
	for(i=0;i<5;i++)
		printf("arg=%ld\n", (long)arg);
	return (void *)((long)arg*(long)arg);//return the square of the passed integer
}

int main()
{
	int r,i;
	pthread_t x[10];//array to store the 10 thread ids
	void *result;
	//when pthread_create and pthread_join successfully execute, they will return 0
	for(i=0;i<10;i++) {//create 10 threads, pass distinct integers (i) to each thread
		r=pthread_create(&x[i], NULL, proc, (void *)(long)i);
		assert(r==0);
	}
	for(i=0;i<10;i++) {//wait for all 10 threads to finish and print returned results individually
		r=pthread_join(x[i], &result);
		assert(r==0);
		printf("returned result from thread %d=%ld\n", i,(long)result);
	}
	return 0; 
} 
