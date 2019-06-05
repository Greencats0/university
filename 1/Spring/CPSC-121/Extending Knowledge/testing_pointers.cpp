#include <iostream>
using namespace std;
const int SIZE = 5;

int main(){
  int numbers[SIZE] = {10, 20, 30, 50, 69};
  int *pointer;
  pointer = numbers;
  for (int i = 0; i < SIZE; i++){
    pointer++;
    cout << *pointer << endl;
  }
  cout << "Gabe" << endl;
  return 0;
}
