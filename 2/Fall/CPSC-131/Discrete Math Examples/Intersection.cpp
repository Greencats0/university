#include <set>
#include <iostream>
#include <algorithm>
// the intersection of a set are all the elements that set a and set b have in common
// like terms

int main() {
  std::set<char> a = {'a', 'b', 'c', 'd'};
  std::set<char> b = {'b', 'd', 'e'};
  std::set<char> c;
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.begin()));
  for(auto element : c){
    std::cout << element << std::endl;
  }
  return 0;
}
