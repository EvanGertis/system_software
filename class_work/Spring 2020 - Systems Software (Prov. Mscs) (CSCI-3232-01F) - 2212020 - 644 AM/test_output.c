#include <stdio.h>

int main()
{
	char c='w';
	int d=97;
	float f=3.1415926;
	double g=2.718281828;
	char s[20]={'h','e','l','l','o',',','w','o','r','l','d','\n','\0'};
	char *p="hello,world";
	printf("char c=%c, int c=%d\n",c,c);
	printf("int d=%d, char d=%c\n",d,d);
	printf("float f=%f\n",f);
	printf("double g=%f\n",g);
	printf("string at s=%s",s);
	printf("string at p=%s\n",p);
	return 0;
}