#include <iostream>
#include <cstdlib>
class A4p2{
	protected:
	       	int var;
	public:
		A4p2() {}

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

class A4p3 : public A4p2{
	private:
		int var2;
	public:
		A4p3(int Var, int Var2){
			var = Var;
			var2 = Var2;
		}
		
		void getsp(){
			std::cout << "Sum of " << var << " and is " << var2 << " is " << (var + var2) << ". ";
		        std::cout << "Product of " << var << " and is " << var2 << " is " << (var * var2) << "." << std::endl;
		}
};

int main(int argc, char * argv[]){
	if(argc < 3){
		std::cout << "ERROR: You must supply a two command line args of type int between 1 and 50" << std::endl;	
		return 0;
	}

	int input = 0;
	int input2 = 0;
	try{
		input = atoi(argv[1]);
		input2 = atoi(argv[2]);
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;
		return 0;
	}
	if((input < 1 || input > 50) || (input2 < 1 || input2 > 50)){
		std::cout << "ERROR: Command line args must be integers between 1 and 50" << std::endl;
	}else{
		A4p3 a4p3(input, input2);
		std::cout << "Iterated integer sequence for 6 is:" << std::endl;
		a4p3.play();
		a4p3.getsp();
	}
	return 0;
}
