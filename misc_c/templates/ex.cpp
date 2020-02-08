#include <stdio.h>

template<class T>
class coordinates{
	T x, y;
public:
	coordinates(T X, T Y){
		x = X;
		y = Y;
	}

	T max();
};

template<class T>
T coordinates<T>::max(){
	return x > y ? x : y;
}

int main(int argc, char *argv[]){
	coordinates<int> coords(7, 100);
	printf("%d\n", coords.max());
}
