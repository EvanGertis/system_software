//demonstrate defining and using a C++ class
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class GSUStudent
{
protected:
	char *name;
	int studentID;
public:
	GSUStudent(const char *pname, int id);//only one constructor that requires two parameters
	void PrintName();
	void PrintStudentID();
	~GSUStudent();//destructor
};

GSUStudent::GSUStudent(const char *pname, int id)
{
	name=(char *)malloc((strlen(pname)+1)*sizeof(char));
	strcpy(name,pname);
	studentID=id;
	printf("constructing a student %s with id %d\n",name,studentID);
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

class GSU_CS_Student : public GSUStudent
{
private:
	int preferred_programming_language;
public:
	GSU_CS_Student(const char *pname, int id, int language);
	~GSU_CS_Student()//removing a GSU_CS_Student object will first call this destructor, then parent's destructor
	{
		printf("goodbye, student %s with studentID %d and preferred language %d.\n",name,studentID,preferred_programming_language);
	}
	void PrintLanguage() {printf("language is %d\n",preferred_programming_language);}
};

//Compare with Java's super
GSU_CS_Student::GSU_CS_Student(const char *pname, int id, int language) : GSUStudent(pname,id)
{//constructing a GSU_CS_Student object will first call parent's constructor, then this constructor.
	preferred_programming_language=language;
	printf("hi CS student %s with studentID %d\n",pname,id);
}

GSU_CS_Student s3("Tom Hanks",12345,67890);//a global object is OK. Allocated first, deallocated last.
//GSU_CS_Student gs[3];//try to create an array of objects; but this is illegal because GSU_CS_Student does not have a constructor that takes no parameters
int main()
{
	GSUStudent s1("Forest Gump",20179999);
	GSUStudent s2("Washington DC",20187777);
	s1.PrintName();
	s1.PrintStudentID();
	s2.PrintName();
	s2.PrintStudentID();

	GSU_CS_Student *ps4=new GSU_CS_Student("leonardo dicaprio",123,456);
	ps4->PrintLanguage();
	delete ps4;//destructor called
	s3.PrintName();
	s3.PrintStudentID();
	//all s1,s2,s3's destructors will be called
	return 0;
}