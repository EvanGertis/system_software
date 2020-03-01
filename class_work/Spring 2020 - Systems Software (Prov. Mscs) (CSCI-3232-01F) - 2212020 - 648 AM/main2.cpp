//this program demonstrates using a class to store four dynamically
//allocated matirces (A,B,AB,BA). A and B are generated according to some rules.
//AB and BA are products of A and B.
//Note: this program needs three files: main2.cpp, a2.cpp, a2.h
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include "a2.h"

using namespace std;

//the program takes two command line arguments to be dimensions for matrices A and B
int main(int argc, char *argv[])
{
	int p,q;
	if(argc!=3) {fprintf(stderr,"usage: %s <p> <q>\n",argv[0]);exit(-1);}
	p=atoi(argv[1]);//get dimensions for A and B from command line
	q=atoi(argv[2]);//A is p by q and B is q by p
	assert(p>0 && q>0);
	
	matrix m(p,q);//construct an object of class matrix
	m.generateMatrix();//generate matrices A and B
	m.computeProducts();//compute AB and BA
	m.printallmatrices();//print all four matrices
	return 0;
}
