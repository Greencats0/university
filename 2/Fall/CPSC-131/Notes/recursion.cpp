#include <iostream>

void numberFunction(int i) {
  std::cout << "The number is: " << i << std::endl;
  i++;
  if(i<10) {
    numberFunction(i);
  }
}

double sum(double *p, size_t start, size_t end){
  if(start == end) { return p[start]; }
  return p[start] + sum(p, start+1, end);
}

size_t isNegative(double value) { return value  < 0 ? 1:0; }
size_t negativeCounter(double *p, size_t start, size_t end){
  if(start == end) { return isNegative(*p); }
  return(isNegative(*p) + negativeCounter(p, start+1, end));
}
int main() {
  double array[5] = {1.4, 2.4, 2.7, -4.5, 6.7};
  std::cout << negativeCounter(array, 0, 5) << std::endl;
  // double result = sum(array, 0, 5);
  // std::cout << result << std::endl;
  return 0;
}

/*
EPP
C string
- palendrome written in pointers

C stdlib
  - strcmp
  - strlen
  - strcat
Linked List
*/
