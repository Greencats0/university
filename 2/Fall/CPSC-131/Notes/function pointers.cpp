#include <functional>
#include <iostream>
// std::function<return(a, b, ......)>
size_t onezero(int a, const std::function<size_t(int)>& predicate){ return predicate(a) ? 1 : 0; }

size_t count(int *p, size_t start, size_t end, const std::function<size_t(int)>& predicate){
  if (start == end){ return predicate(p[start]); }
  return predicate(p[start]) + count(p, start+1, end, predicate);
}

template <typename T>
T calculate(T* p, size_t start, size_t end, std::function<T(T,T)>& function){
  if(start == end) { return p[start]; }
  return function(p[start], calcuate(p, start+1, end, function));
}

int main() {
  int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  size_t printMe = count(x, 0, 6, [](int a) { return (a % 2 == 0);});
  int calcuatedArray = calculate<int>(x, 0, 10, [](const int& a, const int& b) { return a + b; });
  std::cout << printMe << std::endl;
}
