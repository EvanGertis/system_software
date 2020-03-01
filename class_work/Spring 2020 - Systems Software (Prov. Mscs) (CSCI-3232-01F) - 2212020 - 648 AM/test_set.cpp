//you only need to know that set is a C++ template container class encapsulating a mathematical set (no duplicated keys are allowed).
//you are NOT required to be able to write codes similar to this file
#include <iostream>
#include <set>

int main () {
  std::set<int> myset;
  std::set<int>::iterator it;
  std::pair<std::set<int>::iterator,bool> ret;
  // set some initial values:
  for (int i=1; i<=5; ++i) myset.insert(i*10);//set:10… 50
  ret = myset.insert(20); //no new element inserted
  if (ret.second==false) it=ret.first;  // "it" now points to element 20
  myset.insert (it,25); // max efficiency inserting
  myset.insert (it,24); // max efficiency inserting
  myset.insert (it,26); // no max efficiency inserting

  int myints[]= {5,10,15}; // 10 already in set, not inserted
  myset.insert (myints,myints+3);
  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  return 0;
}
