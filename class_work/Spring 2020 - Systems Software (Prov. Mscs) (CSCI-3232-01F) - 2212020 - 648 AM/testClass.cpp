//demonstrate usage of struct and class in C++. Note: class is not available in C.
#include<iostream>
 
using namespace std;
//struct coordinate;
//struct coordinate;//no problem: a struct can be declared 0 or more times
struct coordinate {//definition of struct coordinate
	int x;//public default access
	int y;
	int z;
};
//class programming;
//class programming;//no problem: a class can be declared 0 or more times
class programming //definition of class programming
{
private: //private default access
	int variable;

public:
	void input_value()
	{
		cout << "In function input_value, Enter an integer\n";
		cin >> variable;
	}

	void output_value()
	{
		cout << "Variable entered is ";
		cout << variable << "\n";
	}
	
	void onemorefunction();
};

void programming::onemorefunction()
{
	if(variable%2)//when variable%2 is nonzero, the condition is satisfied
		cout<< "Variable is odd\n";
	else
		cout<< "Variable is even\n";
}

int main(int argc, char *argv[])
{
	programming object;

	object.input_value();
	object.output_value();
	object.onemorefunction();

	//object.variable;  //Will produce an error because variable is private
	struct coordinate c;
	c.x=10; c.y=20; c.z=30;//OK: struct's member has public default access
	cout<<"c.x="<<c.x<<"\tc.y="<<c.y<<"\tc.z="<<c.z<<endl;
	return 0;
}