#include "rectangle.h"

Rectangle::Rectangle(int w, int h){
	width = new int;
	height = new int;
	*width = w;
	*height = h;
}

Rectangle::~Rectangle(){}
