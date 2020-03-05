//another demonstration of race conditions
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NITER 1000000

int cnt = 0;//global variable to be shared among the threads created in main

void *CountFun(void * arg)
{
	int i, tmp;//Note: i, temp are local variables, i.e. not shared among the threads
	for(i = 0; i < NITER; i++)   
	{
		tmp = cnt;      /* copy the global cnt locally */
		tmp = tmp+1;    /* increment the local copy */
		cnt = tmp;      /* store the local value into the global cnt */ 
		//if we replace the above three statements with cnt++, does the race condition remain?
	}
	return NULL;
}

int main(int argc, char * argv[])
{
	int rt,i;
	pthread_t t[2];

	for(i=0;i<2;i++)
	{
		rt=pthread_create( &t[i], NULL, CountFun, NULL);
		if( rt!=0 )
		{	fprintf(stderr,"Thread %d creation failed: %d\n", i,rt); exit(0);}
	}

	for(i=0;i<2;i++)
	{
		rt=pthread_join( t[i], NULL);
		if( rt!=0 )
		{	fprintf(stderr,"Wait for thread %d failed: %d\n", i,rt); exit(0);}
	}

	if (cnt < 2 * NITER) 
		printf("\n BOOM! cnt is [%d], should be %d\n", cnt, 2*NITER);//race effects appear here
	else
		printf("\n OK! cnt is [%d]\n", cnt);

	return 0;
}
