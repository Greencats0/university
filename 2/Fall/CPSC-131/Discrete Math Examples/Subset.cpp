#include <set>
#include <iostream>
#include <algorithm>
// the union of a set is all of the elements in n amount of sets without any duplicates
// more or less the universal set of all the sets

int main() {
  std::set<char> a = {'a', 'b', 'c', 'd'};
  std::set<char> b = {'b', 'd', 'e'};
  // std::set<char> c;
  if(std::includes(a.begin(), a.end(), b.begin(), b.end())){
    std::cout << "a is a subset of b" << std::endl;
  }
  // for(auto element : c){
  //   std::cout << element << std::endl;
  // }
  return 0;
}
