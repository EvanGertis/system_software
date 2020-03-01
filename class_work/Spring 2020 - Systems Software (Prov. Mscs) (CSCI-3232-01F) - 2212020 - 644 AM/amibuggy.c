//This is not a complete program; but demonstrates some commonly found
//bugs written by a programmer familiar with Java

char [] myfun1(int num)
{
	char myarr[num];
	int i;
	for(i=0;i<num;i++)
		myarr[i]=i+1;
	return myarr;//buggy: cannot return local array
}

char [] myfun2()
{
	char myarr[10];
	int i;
	for(i=0;i<10;i++)
		myarr[i]=i+1;
	return myarr;//buggy: cannot return local array
}

char *myfun3(int num)
{
	char *myarr=(char *)malloc(num*sizeof(char));
	return myarr;//OK: return a pointer pointing to dynamically allocated array on heap
}//Note: C/C++ do not have garbage collector. It is the responsiblity of the caller of myfun3 to free the num bytes allocated by myfun3

char *myfun4()
{
	char myarr[10];
	int i;
	for(i=0;i<10;i++)
		myarr[i]=i+1;
	return myarr;//buggy: cannot return local array
}