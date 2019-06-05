// Dynamic array initialization based on amount of lines in given file
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
  string line;
  ifstream stream;
  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Extending Knowledge/midtermPractice.cpp");
  size_t counter = 0;
  while(getline(stream, line)){
    counter++;
  }
  stream.close();
  int *array = new int[counter];
  for(size_t i = 0; i < counter; i++){
    array[i] = i;
  }
  for(size_t i = 0; i < counter; i++){
    cout << array[i] << endl;
  }
  delete [] array;
  array = nullptr;
  return 0;
}
