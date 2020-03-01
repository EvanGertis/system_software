//This program gets a year from command line argument
//and determines if it is a leap year
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
	int year;

	if(argc!=2)//argc is the number of command line arguments plus 1.
	{
		fprintf(stderr,"usage: %s <year>\n",argv[0]);//argv[0] is pointer to program name
		exit(EXIT_FAILURE);
	}

	year=atoi(argv[1]);//convert the <year> the user enters after program name into an integer and saves it in the variable year
	//Alternatively, you can also get year using "scanf("%d", &year);", through standard input, similar to Java's Scanner(System.in).
	if ( year%400 == 0)//% is the modular operator and the result of (year%400) is the remainder of year divided by 400
		printf("%d is a leap year.\n", year);
	else if ( year%100 == 0)
		printf("%d is not a leap year.\n", year);
	else if ( year%4 == 0 )
		printf("%d is a leap year.\n", year);
	else
		printf("%d is not a leap year.\n", year);  

	return 0;
}