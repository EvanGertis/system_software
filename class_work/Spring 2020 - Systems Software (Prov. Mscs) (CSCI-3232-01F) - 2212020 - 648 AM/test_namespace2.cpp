#include <iostream> 
using namespace std;

// Variable created inside namespace
namespace first
{ 
    int val = 500;
}

namespace first //Multiple namespace blocks with the same name are allowed. All declarations within those blocks are declared in the named scope.
{ 
    int getValue() { return 15; }
}

int val = 100; // Global variable
  
int main() 
{ 
    
    int val = 200;// Local variable
//In C, we cannot access a global variable if we have a local variable with same name
    cout << val << '\n';//local
	cout << ::val << '\n';//global: OK in C++; unavailable in C
    cout << first::val << '\n';//namespace
	cout << first::getValue() << '\n';//namespace
    return 0; 
}