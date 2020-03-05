all: badcnt   goodcnt   norace   pthread_ex1   pthread_ex2   race   testThread1   testThread2   testThread
badcnt: badcnt.c
	gcc -o badcnt -pthread badcnt.c
goodcnt: goodcnt.c
	gcc -o goodcnt -pthread goodcnt.c
norace: norace.c
	gcc -o norace -pthread norace.c
pthread_ex1: pthread_ex1.c
	gcc -o pthread_ex1 -pthread pthread_ex1.c
pthread_ex2: pthread_ex2.c
	gcc -o pthread_ex2 -pthread pthread_ex2.c
race: race.c
	gcc -o pthread_ex2 -pthread pthread_ex2.c
testThread1: testThread1.c
	gcc -o testThread1 -pthread testThread1.c	
testThread2: testThread2.c
	gcc -o testThread2 -pthread testThread2.c
testThread: testThread.c
	gcc -o testThread -pthread testThread.c

