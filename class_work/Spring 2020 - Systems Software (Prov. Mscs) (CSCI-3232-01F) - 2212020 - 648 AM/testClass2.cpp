//demonstrate defining and using a C++ class
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class GSUStudent
{
	char *name;//private default access
	int studentID;
public:
	GSUStudent(const char *pname, int id);
	GSUStudent();//two constructors
	void PrintName();
	void PrintStudentID();
	~GSUStudent();//destructor
};

GSUStudent::GSUStudent()
{
	name=(char *)malloc(sizeof(char)*100);
	strcpy(name,"Forest Gump");
	studentID=20179999;
}

GSUStudent::GSUStudent(const char *pname, int id)
{
	name=(char *)malloc((strlen(pname)+1)*sizeof(char));
	strcpy(name,pname);
	studentID=id;
}

GSUStudent::~GSUStudent()
{
	printf("deallocating student with name %s and id %d\n",name,studentID);
	free(name);
}

void GSUStudent::PrintName()
{
	printf("name is %s\n",name);
}

void GSUStudent::PrintStudentID()
{
	printf("studentID is %d\n",studentID);
}

int main()
{
	GSUStudent s1;
	GSUStudent s2("Washington DC",20187777);
	s1.PrintName();
	s1.PrintStudentID();
	//s1.~GSUStudent();//Don't do this! See https://en.cppreference.com/w/cpp/language/destructor: The destructor may also be called directly, e.g. to destroy an object that was constructed using placement-new or through an allocator member function such as std::allocator::destroy(), to destroy an object that was constructed through the allocator. Note that calling a destructor directly for an ordinary object, such as a local variable, invokes undefined behavior when the destructor is called again, at the end of scope. 
	s2.PrintName();
	s2.PrintStudentID();
	GSUStudent *p3=new GSUStudent("xxx",2019);
	p3->PrintName();
	p3->PrintStudentID();
	delete p3;//you should do this when the object on the heap is no longer needed;
	//if you don't delete p3, the destructor may not be called, even though the object will be removed from heap when the process terminates.
	return 0;
}