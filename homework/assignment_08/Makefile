all: a8p1 A8p2_unixpipe A8p2_namedpipe A8p2_shm
a8p1: a8p1.c
	gcc -o a8p1 a8p1.c
A8p2_unixpipe: A8p2_unixpipe.c
	gcc A8p2_unixpipe.c -o A8p2_unixpipe -lrt
A8p2_namedpipe: A8p2_namedpipe.c
	gcc A8p2_namedpipe.c -o A8p2_namedpipe -lrt
A8p2_shm: A8p2_shm.c
	gcc A8p2_shm.c -o A8p2_shm -lrt
