#include <stdio.h>

class Rectangle{
	int * width;
	int * height;

public: 
	Rectangle(int, int);
	~Rectangle();
	void printMe(){
		printf("Dimensions %d by %d \n", *width, *height);
	}
};
