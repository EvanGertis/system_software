//This program demonstrates the usage of ordinary pipes, which is unidirectional
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 4
#define READ_END	0
#define WRITE_END	1

int dotProduct(int a,int b){
	return a*b;
}

int main(void)
{
	int write_integers[BUFFER_SIZE];
	int read_integers[BUFFER_SIZE];
	pid_t pid;
	int fd[2];
	time_t t;
	//initialize RNG
	srand((unsigned)time(&t));
	for(int i=0; i < sizeof(write_integers)/sizeof(int); i++){
		int n = (rand() - 49) % 49;
		write_integers[i] = n;
	}

	/* create the pipe */
	if (pipe(fd) == -1) {//you can type "man 2 pipe" inside Linux to get help for the function "pipe"; or visit http://linux.die.net/man/3/pipe
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	pid = fork();/* now fork a child process */
	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}
	else if (pid > 0) {  /* parent process */
		//sleep(2);//the child will read the message no matter whether the parent sleeps or not
		/* parent is used as a writer, so close the unused read end of the pipe */
		close(fd[READ_END]);//if you remove this line, the program might still work. However it is best practice to close unused fd. See https://stackoverflow.com/questions/19265191/why-should-you-close-a-pipe-in-linux

		/* write to the write end of the pipe */
		for(int i=0; i < BUFFER_SIZE; i++)
			write(fd[WRITE_END], &write_integers[i], sizeof(int));
		
		printf("parent sent : ");
		for(int i=0; i < sizeof(write_integers)/sizeof(int); i++)
			printf(" %d  ", write_integers[i]);
		printf("\n");
		/* close the write end of the pipe */
		close(fd[WRITE_END]);
	}
	else { /* child process */
		/* child is used as a reader, so close the unused write end of the pipe */
		close(fd[WRITE_END]);//if you remove this line, the program might still work. However it is best practice to close unused fd. See https://stackoverflow.com/questions/19265191/why-should-you-close-a-pipe-in-linux

		/* read from the read end of the pipe */
		for(int i=0; i < BUFFER_SIZE; i++)
			read(fd[READ_END], &read_integers[i], sizeof(int));
		
		printf("child received: ");
		for(int i=0; i < BUFFER_SIZE; i++)
			printf(" %d ", read_integers[i]);
		printf("\n");
		int a=read_integers[0], b=read_integers[1], c=read_integers[2], d=read_integers[3];
		printf("inner product of (%d,%d) and (%d,%d) is", a, b, c, d);
		printf(" %d and %d \n", dotProduct(a,b), dotProduct(c,d));
		/* close the read end of the pipe */
		close(fd[READ_END]);
	}

	return 0;
}
