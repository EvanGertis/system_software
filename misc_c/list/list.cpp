#include <iostream>
#include <list>

int main(){

	std::list<int> l;
	int n;

	std::cout << "Enter some integers: \n";

	do{
		std::cin >> n;
		l.push_back(n);
	
	}while(n);

	std::cout << "my list is " << l.size() << "numbers long \n";

	return 0;
}
