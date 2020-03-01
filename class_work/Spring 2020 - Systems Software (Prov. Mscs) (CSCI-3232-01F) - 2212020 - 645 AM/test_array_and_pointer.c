//another demonstration of usage of pointers and arrays
#include <stdio.h>

int getsum(int *a, int len)
{
	int i,s=0;
	for(i=0;i<len;i++) s+=a[i];
	return s;
}//getsum

int main(int argc, char *argv[])
{
	int arr[5]={6,7,8,9,10};
	printf("%d, %d\n", arr[2], arr[4]);
	printf("%d, %d\n", *(arr+2), *(arr+4));//same as arr[2], arr[4]
	int *p=arr+3, *q=&(arr[3]);
	printf("%d, %d\n",*p,*q);//*p and *q are both the same as arr[3]
	int sum=getsum(arr,5);
	printf("sum of elements of array arr is %d\n",sum);
	
	int y[10]={1,2,3,4,5};//partial initialization of all array elements are OK; uninitialized elements will be 0
	int z[10];//uninitialized array; do not assume elements are 0
	int i;
	for(i=0;i<10;i++) printf("%d  ",y[i]); printf("\n");
	for(i=0;i<10;i++) printf("%d  ",z[i]); printf("\n");
	return 0;
}
