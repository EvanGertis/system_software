//demonstration of usage of template in C++.
//you only need to know that template supports generic programming.
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
	return 0;
}