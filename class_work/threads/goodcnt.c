//adaptation from badcnt.c; using semaphore to remove race conditions
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>//for sem_init, sem_wait, sem_post
#include <errno.h>

#define NITER 1000000

//see http://pubs.opengroup.org/onlinepubs/9699919799/
sem_t s1;//Declare the semaphore global variable
int cnt = 0;//global variable to be shared among the threads created in main

void *CountFun(void * arg)
{
	int i, tmp;
	for(i = 0; i < NITER; i++)   
	{//sem_wait and sem_post both return 0 for success and -1 for error
		sem_wait(&s1);//If the value of the semaphore is negative, the calling process/thread blocks; one of the blocked processes/threads wakes up when another process/thread calls sem_post.
		tmp = cnt;      /* copy the global cnt locally */
		tmp = tmp+1;    /* increment the local copy */
		cnt = tmp;      /* store the local value into the global cnt */
		sem_post(&s1);//It increments the value of the semaphore and wakes up a blocked process/thread waiting on the semaphore, if any.
	}
	return NULL;
}

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		fprintf(stderr,"usage: %s <semaphore_initial_value>.\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int val=atoi(argv[1]);//value to initialize our semaphore
	if(val<1 || val>2)
	{
		fprintf(stderr,"<semaphore_initial_value> has to be 1 or 2.\n");
		exit(EXIT_FAILURE);
	}
	if(sem_init(&s1, 0, val)==-1)//Initialize the semaphore using val
	{//If the second argument of sem_init (pshared) has a non-zero value, then the semaphore is shared between processes; in this case, any process that can access the semaphore sem can use sem for performing sem_wait(), sem_trywait(), sem_post(), and sem_destroy() operations.
		fprintf(stderr,"sem_init failed. errno=%d\n",errno);
		exit(1);
	}//int sem_init(sem_t *sem, int pshared, unsigned value);

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
		printf("\n BOOM! cnt is [%d], should be %d\n", cnt, 2*NITER);
	else
		printf("\n OK! cnt is [%d]\n", cnt);

	return 0;
}
