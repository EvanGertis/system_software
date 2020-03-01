//This program tests usage of one and two dimensional arrays
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
	int a[3]={1,2,3},b[3]={4,5,6};//Note: a.length and b.length are wrong. Not valid in C/C++.
	int c[2][3]={{1,2,3},{4,5,6}},d[2][3]={{10,20,30},{40,50,60}};
	int i,j;
	for(i=0;i<3;i++) printf("%d\t",a[i]+b[i]); printf("\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",c[i][j]+d[i][j]); 
		}
		printf("\n");
	}
	//a=b;//wrong! array name cannot be reassigned; if it were allowed, you will lose track of existent storage
	int *p;
	p=a;//OK: p is allowed to point to any valid storage
	for(i=0;i<3;i++) printf("%d\t",p[i]); printf("\n");
	p=b;//p is reassigned and this is still OK: p now points to different valid storage
	for(i=0;i<3;i++) printf("%d\t",p[i]); printf("\n");
	return 0;
}