#include "mysquare.c"

int main(int argc,char * argv[]){
	char * a = argv[1];
	int N = atoi(a);
	int array[N];

	generateNums(array, sizeof(array)/sizeof(int));
	printNums(array,  sizeof(array)/sizeof(int));
	squareNums(array,  sizeof(array)/sizeof(int));
	printNums(array,  sizeof(array)/sizeof(int));

	return 0;
}
