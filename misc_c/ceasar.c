#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char * plaintext){
	for(int i=0; i < (sizeof(plaintext)/sizeof(char)); i++){
		itoa((atoi((plaintext+i))+3),(plaintext+i),10);
		printf("%c", *(plaintext+i));
	}
}

void decrypt(char * encipheredtext){
	for(int i=0; i < (sizeof(encipheredtext)/sizeof(char)); i++){
		itoa((atoi((encipheredtext+i))-3),(encipheredtext +i),10);
		printf("%c", *(encipheredtext+i));
	}
}

int main(int argc, char * argv[]){
	char * str = argv[1];
	encrypt(str);
	decrypt(str);
}
