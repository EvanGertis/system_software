#include <stdio.h>

union data {
	int x;
	int y;
};
int main(int argc, char* argv[]){
	union data mydata;
	mydata.y = 1;
	mydata.x = 2;

	printf("%d \n", mydata.y);
	printf("%d \n", mydata.x);
	return 0;
}
