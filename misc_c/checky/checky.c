#include <stdlib.h>
#include <stdio.h>

struct person{
	int age;
	char * name;
};

int main(){
	struct person *johnny = malloc(sizeof(struct person));
	printf("%lu \n", sizeof(johnny));
	return 0;
}
