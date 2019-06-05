#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
using namespace std;

int main(){
  string inputString = "Hello World!";
  const int sizeOfString = inputString.length();
  char newCharArray[sizeOfString];
  strcpy(newCharArray, inputString.c_str());
  cout << "Size of string: " << sizeOfString << endl;
  for (int a = 0; a < sizeOfString; a++){
    cout<< newCharArray[a] << endl;
  }
  return 0;
}
