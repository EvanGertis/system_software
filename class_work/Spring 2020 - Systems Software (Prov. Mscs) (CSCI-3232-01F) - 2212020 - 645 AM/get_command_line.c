//demonstrates how to get command line arguments.
//compare java's main: public static void main(String args [])
//In Java, it is not easy to get program name.
#include <stdio.h>
int main(int argc, char *argv[]) {
	int i;
	printf("program name is %s\n",argv[0]);//In C/C++, you can get program name by argv[0]
	printf("there are %d command line arguments:\n", argc-1);
	for(i=1;i<argc;i++) printf("%s\n",argv[i]);//print all command line arguments
	//command line arguments (through argv[1], argv[2],...) are common ways to supply input information to a C/C++ program, as in Java/Bash/Python programs.
	//Alternatively, you can also use scanf (in C) or std::cin (in C++) to supply input information to a program.
	//for examples, see LeapYear_cmdline.c, test_list.cpp, test_vector.cpp, or the following:
	//int myint;
	//scanf("%d", &myint);
	//std::cin >> myint;
	return 0;
}
