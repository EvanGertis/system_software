#include <iostream>
#include <stdlib.h>
int main(int argc, char* argv[]){
	int argument;
	while(std::cin >> argument){
		try{
			std::cout << " " << argument*argument;
		}catch(std::exception e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
