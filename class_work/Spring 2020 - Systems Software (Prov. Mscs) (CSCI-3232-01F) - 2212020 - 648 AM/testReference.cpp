//This program tests the usage of refernce in C++. Note: reference is not available in C.
#include <iostream>

using namespace std;

struct coordinate {
	int x;
	int y;
	int z;
};

void exchange(int & r1, int & r2)
{
	int t;
	t=r1;
	r1=r2;
	r2=t;
}

void incrementXcoordinateThroughReference(struct coordinate & r)
{
	r.x++;
}

void incrementXcoordinateThroughPointer(struct coordinate *pr)
{
	pr->x++;
}

int main(int argc, char *argv[])
{
	int v=15;
	//int &y;//error: a reference variable need to be initialized
	//y=v;//a reference variable must be initialized when it is declared
	int &r=v;//r is a reference of type int; it refers to v
	int x=r+22;//r will take the value of 15 on the right hand side since it refers to v
	cout<<"v="<<v<<"\tx="<<x<<"\tr="<<r<<endl;
	exchange(v,x);//v and x's values will be changed
	//v and x's values are exchanged; r still refers to v so printed r value reflects v's new value
	cout<<"v="<<v<<"\tx="<<x<<"\tr="<<r<<endl;
	r=x;//the reference r still refers to v; the value of x is assigned to "r(v)"
	cout<<"r="<<r<<endl;
	cout<<"v="<<v<<endl;//v's value is updated again because of "r=x"
	//int &r2;
	//cout<<"r2="<<r2<<endl;//error: r2 does not reference to any variable
	
	struct coordinate a;
	a.x=10; a.y=20; a.z=30;
	cout<<"a.x="<<a.x<<"\ta.y="<<a.y<<"\ta.z="<<a.z<<endl;
	struct coordinate &ra=a;//ra is a reference of type struct coordinate; it refers to a
	incrementXcoordinateThroughReference(ra);
	cout<<"a.x="<<a.x<<"\ta.y="<<a.y<<"\ta.z="<<a.z<<endl;
	incrementXcoordinateThroughPointer(&a);
	cout<<"a.x="<<a.x<<"\ta.y="<<a.y<<"\ta.z="<<a.z<<endl;
	return 0;
}