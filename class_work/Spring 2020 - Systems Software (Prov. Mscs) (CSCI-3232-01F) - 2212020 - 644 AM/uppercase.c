//This program demonstrates some character I/O and processing functions
#include <stdio.h> //contains I/O functions such as getchar, putchar, printf
#include <ctype.h> //contains prototype of function toupper

int main() {// starting point for execution of our C program
	int c; // integer variable to store a character

	printf("Type a string of character to be converted to ");
	printf("uppercase, then press enter\n Ctrl+D to exit\n\n");
	while (( c = getchar()) != EOF) 
		putchar(toupper(c));
	return 0;
}
