//Note: this program needs three files: main2.cpp, a2.cpp, a2.h
#include <iostream>
#include "a2.h"

matrix::~matrix()//deallocate all memory
{
	int i;
	for(i=0;i<p;i++) {
		delete [] A[i];
	}
	delete [] A;
	for(i=0;i<q;i++) {
		delete [] B[i];
	}
	delete [] B;
	for(i=0;i<p;i++) {
		delete [] AB[i];
	}
	delete [] AB;
	for(i=0;i<q;i++) {
		delete [] BA[i];
	}
	delete [] BA;
}

void matrix::printMatrix(int **m, int a, int b)//a: rows; b: cols
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			std::cout<<m[i][j]<<"\t";
		std::cout<<"\n";
	}
	std::cout<<"\n\n";
}

void matrix::printallmatrices()
{
	std::cout<<"A:\n";
	printMatrix(A,p,q);
	std::cout<<"B:\n";
	printMatrix(B,q,p);
	std::cout<<"AB:\n";
	printMatrix(AB,p,p);
	std::cout<<"BA:\n";
	printMatrix(BA,q,q);
}

/* Compare with Java
-----One Dimensional Array
int[] num = new int[5];
int[] num = {1,2,3,4,5};

-----Multidimensional array
int[][] num = new int[5][2];

-----Ragged Array (or Non-rectangular Array)
int[][] num = new int[4][];
 num[0] = new int[1];
 num[1] = new int[5];
 num[2] = new int[2];
 num[3] = new int[3];
*/
matrix::matrix(int a, int b)//dynamically allocate storage for the four matrices
{
	p=a; q=b;
	A=(int **) new int *[p];//pay attention to syntax based on data types!
	int i;
	for(i=0;i<p;i++) {
		A[i]=(int *) new int[q];
	}
	B=(int **) new int *[q];
	for(i=0;i<q;i++) {
		B[i]=(int *) new int[p];
	}
	AB=(int **)new int *[p];
	for(i=0;i<p;i++) {
		AB[i]=(int *)new int[p];
	}
	BA=(int **) new int *[q];
	for(i=0;i<q;i++) {
		BA[i]=(int *) new int[q];
	}
}

//compute matrix productes
//see https://en.wikipedia.org/wiki/Matrix_multiplication Section "Matrix product (two matrices)"
void matrix::computeProducts()//note that in general A*B is not equal to B*A when A,B are matrices of dimension p by q and q by p respectively
{
	int i,j,k;
	for(i=0;i<p;i++)//compute AB=A*B
		for(j=0;j<p;j++)
		{
			int sum=0;
			for(k=0;k<q;k++)
				sum+=A[i][k]*B[k][j];
			AB[i][j]=sum;
		}
	for(i=0;i<q;i++)//compute BA=B*A
		for(j=0;j<q;j++)
		{
			int sum=0;
			for(k=0;k<p;k++)
				sum+=B[i][k]*A[k][j];
			BA[i][j]=sum;
		}
}

void matrix::generateMatrix()//generate matrices A and B
{
	int i,j;
	for(i=0;i<p;i++)
		for(j=0;j<q;j++) {
		A[i][j]= i+j+1;//can be replaced with random integers
		B[j][i]=(i+1)*(j+1);
		}
}