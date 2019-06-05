// Dynamic memory and array
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
  int size;
  cout << "Please enter number of scores: ";
  cin >> size;
  int *scoresPointer;
  scoresPointer = new int[size];
  for (int i = 0; i < size; i++){
    srand(time(NULL));
    int number = rand() % 100 + 1;
    number = scoresPointer[i];
    cout << scoresPointer[i] << endl;
  }
  return 0;
}
