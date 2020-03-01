#include <stdio.h>

struct MyStruct {
	int a;
	char c;
};

int main(){
	int a[5];
	int *pa;
	printf("size of array a is %ld\n", sizeof(a));
	printf("size of pa is %ld\n", sizeof(pa));//note sizeof(pa) differs from sizeof(a)
	printf("size of a short is %ld\n", sizeof(short));
	printf("size of a int is %ld\n", sizeof(int));
	printf("size of a long is %ld\n", sizeof(long));
	printf("size of a char is %ld\n", sizeof(char));
	printf("size of a MyStruct is %ld\n", sizeof(MyStruct));
	return 0;
}
