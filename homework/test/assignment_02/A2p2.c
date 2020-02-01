#include <stdio.h>

int main(int argc, char* argv[]){
	int i  = 0;
	for(; i < 6; i++){
		printf("hello world\n");
	}
	while(i < 12){
		printf("hello world\n");
		i++;
	}
	do{
		printf("hello world\n");
		i++;
	}while(i < 18);
	
	return 0;

}
