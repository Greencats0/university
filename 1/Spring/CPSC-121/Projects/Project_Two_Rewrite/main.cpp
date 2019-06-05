// Written by Jared Dyreson
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <cstring>

using namespace std;

size_t numberOfStudents(ifstream &stream){
  size_t number = 0;
  string line;
  while(getline(stream, line)){
    if(isalpha(line[0])){
      number++;
    }
  }
  return number;
}

int main(){
  ifstream stream;
  stream.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project Two/CPSC121dataUpdated.txt");
  size_t number = numberOfStudents(stream);
  int *ptr = new int[number];
  cout << number << endl;
  for(size_t i = 0; i < number; i++){
    cout << ptr[i] << endl;
  }
  stream.close();
  return 0;
}
