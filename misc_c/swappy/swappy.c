#include <stdio.h>

void swap(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

int main(int argc, char * argv[]){
	int arr[] = {1,2,3,4,5};
	swap(&arr[0], &arr[2]);
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
		printf("%d | ", arr[i]);
	}
	printf("\n");
	return 0;
}
