// this program uses knowledge of arrays and pointers
// level: intermidiate
#include <iostream>
using namespace std;

int main(){
  const int A = 2;
  const int B = 3;
  int array[A][B];
  int max = 0;
  int *pMax = &max;
  for (int a = 0; a < A; a++){
    for (int b = 0; b < B; b++){
      cout<< "Num: ";
      cin>> array[a][b];
    }
  }
  for (int a = 0; a < A; a++){
    for (int b = 0; b < B; b++){
      cout<< array[a][b] << endl;
      if (array[a][b] > max){
        max = array[a][b];
      }
    }
  }
  cout<< "max is " << max << endl;
  cout<< "Pointer in memory for max is: " << pMax << endl;
  return 0;
}
