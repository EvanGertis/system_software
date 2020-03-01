//demonstrate usage of pointers in the context of arrays
#include <stdio.h>

int main(int argc, char *argv[])
{
	int arr[2][3]={{5,6,7},{8,9,10}};
	printf("%d, %d\n", arr[0][1], arr[1][2]);
	printf("%d, %d\n", *(*arr+1), *(*(arr+1)+2));//same as arr[0][1], arr[1][2]; name of two dimensional array is double pointer (pointer to pointer)
	int *pa=arr[0];
	int i;
	for (i=0;i<6;i++)
		printf("%d\t",*(pa+i));//two dimensional arrays are actually stored linearly in memory
	printf("\n");
	int *pb=&arr[0][0];//Note: pb is actually the same as pa; see the print out of their values below
	for (i=0;i<6;i++)
		printf("%d\t",*(pb+i));//two dimensional arrays are actually stored linearly in memory
	printf("\npa=%p\npb=%p\n",pa,pb);//pa and pb have the same values
	return 0;
}
