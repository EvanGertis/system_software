//you only need to know that list is a C++ template container class encapsulating doubly linked list.
//you are NOT required to be able to write codes similar to this file
#include <iostream>
#include <list>

int main () {
  std::list<int> mylist;
  int myint;
  std::cout << "Enter some integers (enter 0 to end):\n";
  do {   std::cin >> myint;
    mylist.push_back (myint);
  } while (myint);
  std::cout << "mylist stores " << mylist.size() << " numbers.\n";
  std::list<int>::iterator li;
  for(li=mylist.begin();li!=mylist.end();li++)
	  std::cout<<*li<<"\t";
  std::cout<<std::endl;
  return 0;
}
