//demonstration of derived classes
#include <iostream>
using namespace std;

class Polygon { //a class with no explicit constructors and destructors
protected:
	int width, height;
public:
	void set_values (int a, int b)
	{ width=a; height=b;}
};

class Rectangle: public Polygon {//Note how this is different than Java in defining a derived (child) class
public:
	int area ()
	{ return width * height; }
};

class Triangle: public Polygon {
public:
	int area ()
	{ return width * height / 2; }
};

int main () {
	Rectangle rect;
	Triangle trgl;
	rect.set_values (4,5);
	trgl.set_values (4,5);
	cout << rect.area() << '\n';
	cout << trgl.area() << '\n';
	return 0;
}