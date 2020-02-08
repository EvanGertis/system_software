#include <stdio.h>
#include <string.h>
int main(int argc, char* argv){
	printf("welcome to the gdb debugging tutorial! Enter yes or no \n");
	char choice[20];
	scanf("%s", choice);

	if(strcmp(choice,"yes") == 0){
		printf("you chose yes \n");
	}
	else{
		printf("you chose no \n");
	}

	return 0;

}
