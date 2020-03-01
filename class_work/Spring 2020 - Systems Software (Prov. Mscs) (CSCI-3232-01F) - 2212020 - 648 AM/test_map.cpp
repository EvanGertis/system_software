//you only need to know that map is a C++ template container class encapsulating a set of key-value pairs. Similar to Java's Hashmap and Treemap.
//you are NOT required to be able to write codes similar to this file
#include <iostream>
#include <map>

int main () {
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;
  mymap['a']=50;  mymap['b']=100;  mymap['c']=150;
  // print content:
  std::cout << "elements in mymap:" << '\n';
  for(it=mymap.begin();it!=mymap.end();it++)
  {
	  std::cout<<it->first<<" => "<<it->second<<"\n";
  }
  it = mymap.find('b');
  if (it != mymap.end())  mymap.erase (it);
  // print updated content:
  std::cout << "updated elements in mymap:" << '\n';
  for(it=mymap.begin();it!=mymap.end();it++)
  {
	  std::cout<<it->first<<" => "<<it->second<<"\n";
  }
  // std::cout << "a => " <<mymap.find('a')->second<<'\n';
  // std::cout << "c => " <<mymap.find('c')->second<<'\n';
  return 0;
}