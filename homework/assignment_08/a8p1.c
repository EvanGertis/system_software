#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>

void toUpper(char * s){
	for (int i = 0; s[i]!='\0'; i++)
      		if(s[i] >= 'a' && s[i] <= 'z') 
         		s[i] = s[i] -32;
}

int main(int argc, char * argv[]){

	char* lowercaseString = argv[1];
	if(fork() == 0){
		printf("I am the child. Printing the original version: %s \n", lowercaseString);
	}
	else{
		toUpper(lowercaseString);
		printf("I am the parent. Printing the complementary upper case version: %s \n", lowercaseString);
	}

	return 0;
}
