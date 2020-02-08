#include <stdio.h>

void func(char &x, char &y, char &z){
	char temp = x;
	x = y;
	y = z;
	z = temp;
}

int main(int arg, char * argv[]){
	char &x =* argv[1];
	char &y =* argv[2];
	char &z =* argv[3];

	func(x, y, z);
	printf("x: %d, y: %d, z: %d", z, x, y);
	return 0;
}
