/**
 * Simple program demonstrating shared memory in POSIX systems.
 * This program uses fork() to get the producer and consumer processes
 * that writes to and reads from the shared memory region named "OS" respectively.
 * Compare this combined version with the separated version: {shm-posix-producer.c, shm-posix-consumer.c}.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()//Link with -lrt
{
	const int SIZE = 4*sizeof(int);
	const char *name = "OS";
	pid_t pid;
	int shm_fd;
	void *ptr;

	/* now fork a child process */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}
	else if (pid > 0) {  /* parent process: consumer */
		printf("In Parent process. I am the consumer: my child pid=%d\n",pid);
		wait(NULL);
		/* open the shared memory segment */
		shm_fd = shm_open(name, O_RDONLY, 0666);//you can type "man 3 shm_open" inside Linux to get help for the function "shm_open"; or visit http://linux.die.net/man/3/shm_open
		if (shm_fd == -1) {
			fprintf(stderr,"open shared memory failed\n");
			exit(-1);
		}

		/* now map the shared memory segment in the address space of the process */
		ptr = mmap(0,SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);//use similar methods to get help for the function "mmap"; see instructions above
		if (ptr == MAP_FAILED) {
			fprintf(stderr,"Map failed in parent\n");
			exit(-1);
		}
		printf("Parent got mapped pointer: %p\n",ptr);
		/* now read from the shared memory region */
		printf("Parent has received:");
		for(int i=0; i < SIZE/sizeof(int); i++)
			printf(" %d ", *((int *)ptr +i));	
		printf("\n");
		int a= *((int *)ptr), b=*((int *)ptr +1), c=*((int *)ptr +2), d=*((int *)ptr +3);
		printf("The inner product of (%d,%d) and (%d,%d) is: ", a,b,c,d);
		printf("%d and %d ", a*c, b*d);
		/* remove the shared memory segment */
		if (shm_unlink(name) == -1) {//use similar methods to get help for the function "shm_unlink"; see instructions above
			fprintf(stderr,"Error removing %s\n",name);
			exit(-1);
		}
		printf("parent done\n");
	}
	else { /* child process: producer */
		printf("In Child process. I am the producer: my pid=%d\n",getpid());
		time_t t;
	        srand(time(&t));
         	int integers[SIZE];
		printf("Generating random integers: ");
            	for(int i=0; i < SIZE/sizeof(int); i++){
	        	int value = (rand() -49) %49;
			integers[i] = value;
			printf(" %d ", value);
		}
          	printf("\n");


		/* create the shared memory segment */
		shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
		if (shm_fd == -1) {
			fprintf(stderr,"open shared memory failed\n");
			exit(-1);
		}

		/* configure the size of the shared memory segment */
		ftruncate(shm_fd,SIZE);//use similar methods to get help for the function "ftruncate"; see instructions above

		/* now map the shared memory segment in the address space of the process */
		ptr = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
		if (ptr == MAP_FAILED) {
			fprintf(stderr,"Map failed in child\n");
			return -1;
		}
		printf("Child got mapped pointer: %p\n",ptr);
		void *ptr2=ptr;//back up the pointer for later use
		/* Now write to the shared memory region. Note we must increment the value of ptr after each write. */
		//another commonly used function to copy data from one memory location to another is memcpy
		//void *memcpy(void *dest, const void *src, size_t n);//use "man memcpy" for more details
		memcpy((int *)ptr, integers, sizeof(int));
		memcpy((int *)ptr+1,integers+1, sizeof(int));
		memcpy((int *)ptr+2,integers+2, sizeof(int));
		memcpy((int *)ptr+3,integers+3, sizeof(int));
		//sprintf(ptr," %d ", integers[0]);//sprintf can write some data (a string) to some specified memory region.
		//sprintf(ptr+1," %d ", integers[1]);//memcpy can copy some arbitrary data in some source region to specified destination region.
		//sprintf(ptr+2," %d ", integers[2]);
		//sprintf(ptr+3," %d ", integers[3]);
		
		printf("Child has sent: ");
		for(int i=0; i < SIZE/sizeof(int); i++)
			printf(" %d ", *((int *)ptr2+i));
		printf("\n");
	}

	return 0;
}
