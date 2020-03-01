//This program tests usage of double pointer
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
	int **pc,**pd;//supposed to hold 2 by 4 matrix
	int i,j;
	pc=malloc(2*sizeof(int*));
	for(i=0;i<2;i++) pc[i]=malloc(4*sizeof(int));
	pd=malloc(2*sizeof(int*));
	for(i=0;i<2;i++) pd[i]=malloc(4*sizeof(int));

	for(i=0;i<2;i++)
		for(j=0;j<4;j++)
			pc[i][j]=i+j+2;
	for(i=0;i<2;i++)
		for(j=0;j<4;j++)
			pd[i][j]=(i+1)*(j+2);
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",pc[i][j]+pd[i][j]); 
		printf("\n");//this is not in the body of the for j loop
	}
	for(i=0;i<2;i++) free(pc[i]);
	free(pc);
	for(i=0;i<2;i++) free(pd[i]);
	free(pd);
	return 0;
}