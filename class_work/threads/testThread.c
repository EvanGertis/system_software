#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <assert.h>

struct test {
	long num1;
	bool check;
};

void *proc(void *arg)
{
	printf("arg=%ld\n", (long)((struct test *)arg)->num1);
	bool test = (bool)((struct test *)arg)->check;
	if(test){
		pthread_exit((void *)99);//if we have this function call, the main will print out "result=99" instead of "result=2016"
	}
	else{
		return (void *)2016;
	}
}

int main(int argc, char * argv[])
{
	bool condition = strcmp(argv[1], "true") == 0 ? true : false;
	int r;
	pthread_t x;
	void *result;
	struct test * argument = (struct test *)malloc(sizeof(struct test));
	argument->num1 = 34;
	argument->check = condition;
	//when pthread_create and pthread_join successfully execute, they will return 0
	r=pthread_create(&x, NULL, proc, (void *)argument);
	assert(r==0);
	r=pthread_join(x, &result);
	assert(r==0);
	printf("result=%ld\n", (long)result);
	return 0; 
} 
