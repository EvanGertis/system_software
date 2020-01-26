#include <stdio.h>

template<class typeParam>
typeParam max(typeParam a, typeParam b){
	return (a > b ? a : b);
}

int main(){
	int a = 3, b = 7;
	double c = 5.5, d = 1.5;
	printf("%d \n", max(a,b));
	printf("%f \n", max(c,d));
	return 0;
}
