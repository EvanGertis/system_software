//demonstration of exception handling using try catch block.
//You only need to know that exception handling serves similar purpose as in Java to deal with runtime error nicely.
//you are NOT required to be able to write codes similar to this file
#include <iostream>

using namespace std;

template <class T, int N> 
class myarray {
	public:
	T mem[N];
	T& operator[] (int x); 
}; 

template <class T, int N> 
T& myarray<T,N>::operator[] (int x) {
	if ((x<0) || (x>=N)) throw 99;
	return mem[x]; 
} 

int main(int argc, char *argv[])
{
	myarray<int,20> a20;
	int i;
	for(i=0;i<20;i++)
		a20[i]=i;
	for(i=0;i<20;i++)
		cout<<a20[i]<<"\t";
	cout<<endl;
	try
	{
		a20[30]=30;
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Number: " << e << '\n';
	}
	return 0;
}