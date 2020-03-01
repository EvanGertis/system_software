//This programs demonstrates crashing when division by 0 occurs.
#include <stdio.h>

int main() {
	int x,y;

	y=54389;
	for (x=10; x>=0; x--)
  		y=y/x;//when x is 0, this assignment will crash the program
	printf("%d\n",y);
	return 0;
}
