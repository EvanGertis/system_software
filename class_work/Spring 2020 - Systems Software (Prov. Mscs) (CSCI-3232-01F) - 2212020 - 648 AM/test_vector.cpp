//you only need to know that vector is a C++ template container class encapsulating array.
//you are NOT required to be able to write codes similar to this file
#include <iostream>
#include <vector>

int main () {
  std::vector<int> myvector;
  int myint;
  std::cout << "Enter some integers (enter 0 to end):\n";
  do {    std::cin >> myint;
    myvector.push_back (myint);
  } while (myint);
  std::cout << "myvector stores " << int(myvector.size()) << " numbers:\n";
  std::vector<int>::iterator vi;
  for(vi=myvector.begin();vi!=myvector.end();vi++)
	  std::cout<<*vi<<"\t";
  std::cout<<std::endl;
  return 0;
}
