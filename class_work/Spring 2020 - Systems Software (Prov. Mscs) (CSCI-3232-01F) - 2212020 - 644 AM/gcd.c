//This program gets two integers from command line
//and prints out the greatest common divisor and
//least common multiple of the two integers
#include <stdio.h>
#include <stdlib.h>
 
void Usage(char *s)
{
	fprintf(stderr,"usage: %s <a> <b>\n",s);
	exit(0);
}

int main(int argc, char *argv[]) {
	int a, b, x, y, t, gcd, lcm;

	if(argc!=3) Usage(argv[0]);

	x = atoi(argv[1]);
	y = atoi(argv[2]);

	a = x; b = y;
	while (b != 0) {//Euclidean algorithm
		t = b;
		b = a % b;
		a = t;
	}

	gcd = a;
	lcm = (x*y)/gcd;

	printf("Greatest common divisor of %d and %d = %d\n", x, y, gcd);
	printf("Least common multiple of %d and %d = %d\n", x, y, lcm);

	return 0;
}