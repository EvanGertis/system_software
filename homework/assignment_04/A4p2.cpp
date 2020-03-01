#include <iostream>
#include <cstdlib>
class A4p2{
	protected:
	       	int var;
	public:
		A4p2(int Var){
			var = Var;
		}

		void play()
		{
			std::cout << var << " ";
			
			int length = 1;
			while(var > 1)
			{
				if(var % 2){
					var = (3*var+2)/2;
				}
				else{
					var = var/2;
				}
				std::cout << var << " ";
				length++;
			};
			std::cout << std::endl;
			std::cout << "Length of the sequece " << length << std::endl;
		}

};

int main(int argc, char * argv[]){
	if(argc < 2){
		std::cout << "ERROR: You must supply a command line arg of type int between 1 and 50" << std::endl;
		return 0;
	}

	int input = 0;
	try{
		input = atoi(argv[1]);
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;
		return 0;
	}
	if(input < 1 || input > 50){
		std::cout << "ERROR: Command line arg must be an integer between 1 and 50" << std::endl;
	}else{
		A4p2 a4p2(input);
		a4p2.play();
	}
	return 0;
}
