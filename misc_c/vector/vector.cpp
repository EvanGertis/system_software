#include <iostream>
#include <vector>

int main(){

	std::vector<int> vec;
	int n;
	std::cout << "Enter some integers: \n";
	do{
		std::cin >> n;
		vec.push_back(n);

	}while(n);
	std::cout << "vec holds" << vec.size() << "numbers\n";


	return 0;
}
