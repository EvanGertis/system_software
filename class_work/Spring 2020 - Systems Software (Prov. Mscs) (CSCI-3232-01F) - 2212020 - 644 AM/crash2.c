//This programs demonstrates crashing when array index is out of bound.
#include <stdio.h>

int main()
{
	int x,y,z[3];

	y=54389;
	for (x=10; x>=1; x--)
		z[y]=y/x;//if the y in z[y] is not 0,1,or 2, then it is out of bound
	printf("%d\n",z[0]);
	return 0;
}
