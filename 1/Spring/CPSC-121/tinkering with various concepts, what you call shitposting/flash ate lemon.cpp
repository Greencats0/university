#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
const int a = 6;
const int b = 23;

void printArray(const int size, int array[a][b]);
int main(){
  ifstream stream;
  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project Two/CPSC121dataUpdated.txt");
  stream.close();
  // http://www.cplusplus.com/forum/beginner/213229/
  // this will allow me to dynamically allocate memory to allow the passage of the array
  int scores[a][b] = {0};
  printArray(b, scores);
  return 0;
}

void printArray(const int size, int array[a][b]){
  for (int i = 0; i < a; i++){
    for (int j = 0; j < b; j++){
      cout << array[i][j] << endl;
    }
  }
}
