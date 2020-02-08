#include <iostream>
#include <map>

int main(){
	std::map<char, int> map;
	std::map<char, int>::iterator it;
	map['a'] = 50;
	map['b'] = 100;
	map['c'] = 150;

//	if(it != map.end())
//	map.erase(it);

	std::cout << "a= " << map.find('a')->second << std::endl;
	std::cout << "b= " << map.find('b')->second << std::endl;
	std::cout << "c= " << map.find('c')->second << std::endl;

	return 0;
}
