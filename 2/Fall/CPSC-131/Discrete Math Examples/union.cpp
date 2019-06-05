#include <set>
#include <iostream>
#include <algorithm>
// the union of a set is all of the elements in n amount of sets without any duplicates
// more or less the universal set of all the sets

int main() {
  std::set<char> a = {'a', 'b', 'c', 'd'};
  std::set<char> b = {'b', 'd', 'e'};
  std::set<char> c;
  std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.begin()));
  for(auto element : c){
    std::cout << element << std::endl;
  }
  return 0;
}
