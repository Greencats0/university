// This will reverse the order of a given number
// Example 13 will be 31
// It can visualize converting from Big Endian to Little Endian

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]){
  std::vector<int> container;
  int number = 13;
  int remainder = 0;
  while(number != 0){
    remainder = number%10;
    container.push_back(remainder);
    number = number/10;
  }
  for(auto element : container){
    std::cout << element;
  }
  std::cout << std::endl;
  return 0;
}
