// Written by Jared Dyreson

#include "parser.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cout << "Str: " << endl;
  getline(cin, s);
  ParsedString helloWorld;
  int yes = helloWorld.lengthOfString(s);
  cout << yes << endl;
  return 0;
}
