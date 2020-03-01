//This program tests usage of one and two dimensional arrays
//using pointer and double pointers
#include <stdio.h>
#include <stdlib.h>

void fun1(int size)
{
	int a[size],i;//a is a variable-sized array; this is supported by GNU but you are not recommended to use
	for(i=0;i<size;i++)
		printf("%d\n",a[i]);
}//fun1

int main(int argc, char *argv[])
{
	int *p, **c;
	int i,j;
	p=(int*)malloc(10*sizeof(int));//allocate an array of 10 integers on heap; p points to the first element of this array
	for(i=0;i<10;i++)
	{
		p[i]=i;//accessing elements of the allocated dynamic array through array syntax; remember p[i] is the same as *(p+i)
		printf("%d\t",p[i]);
	}
	printf("\n\n\n");
	c=(int**)malloc(10*sizeof(int*));//c will be used to access a 10 by 20 array
	for(i=0;i<10;i++)
	{
		c[i]=(int*)malloc(20*sizeof(int));
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<20;j++)
		{
			c[i][j]=i+j+1;
			printf("%d\t",c[i][j]); 
		}
		printf("\n");
	}
	free(p);//this frees the array of 10 integers on heap
	for(i=0;i<10;i++)	free(c[i]);//each iteration frees the array of 20 integers on heap
	free(c);//this frees the array of 10 pointers on heap
	//p and c are still on stack and can be reused before return if desired
	return 0;
}