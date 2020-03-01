//demonstrate dynamic storage usage with new and delete in C++
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int *p;
	p=new int;
	*p=5;
	cout<<"the integer at address p is ";
	cout<<*p<<endl<<endl;
	delete p;//dynamic storage is recycled; recycle as early as possible
	
	/* Compare with Java
-----One Dimensional Array
int[] num = new int[5];
int[] num = {1,2,3,4,5};*/
	int *num;//Note: new (and C malloc function) returns a pointer and you can assign the returned pointer to a pointer variable, but not to an array (like int[] num ). This is drastically different than Java!
	num= new int [5];
	if(num==NULL) {cerr<<"memory allocation failed."<<endl; exit(-1);}//if new returns NULL, then memory allocation failed.
	int i,j;
	cout<<"num"<<endl;//print out the pointer value
	for(i=0;i<5;i++)
	{
		num[i]=i+1;
		cout<<num[i]<<"\t";
	}
	cout<<endl<<endl;
	delete [] num;//dynamic storage is recycled; recycle as early as the storage is no longer needed
	
	/* Compare with Java
	-----Multidimensional array
int[][] num2 = new int[5][4];*/
	int **num2;
	num2=new int *[5];//again, you cannot assign the returned pointer to two dimensional array (like int[][] num2).
	//test allocation success here
	if(num2==NULL) {cerr<<"memory allocation failed."<<endl; exit(-1);}
	cout<<"num2"<<endl;
	for(i=0;i<5;i++)
	{
		num2[i]=new int [4];
		if(num2[i]==NULL) {cerr<<"memory allocation failed."<<endl; exit(-1);}
		for(j=0;j<4;j++)
		{
			num2[i][j]=i+j+1;
			cout<<num2[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	for(i=0;i<5;i++) delete [] num2[i];
	delete [] num2;//dynamic storage is recycled; recycle as early as possible
	
	/* Compare with Java
	-----Ragged Array (or Non-rectangular Array)
int[][] num = new int[4][];
 num[0] = new int[4];
 num[1] = new int[5];
 num[2] = new int[6];
 num[3] = new int[7];
*/
	int **num3;
	num3=new int *[4];
	//test allocation success here
	if(num3==NULL) {cerr<<"memory allocation failed."<<endl; exit(-1);}
	cout<<"num3"<<endl;
	for(i=0;i<4;i++)
	{
		num3[i]=new int [i+4];
		if(num3[i]==NULL) {cerr<<"memory allocation failed."<<endl; exit(-1);}
		for(j=0;j<i+4;j++)
		{
			num3[i][j]=i+j+1;
			cout<<num3[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	for(i=0;i<4;i++) delete [] num3[i];
	delete [] num3;//dynamic storage is recycled; recycle as early as possible
	return 0;
}//main