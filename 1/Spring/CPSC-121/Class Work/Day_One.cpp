// 2spoopyforyou
#include <iostream>
#include <string>
using namespace std;

int calc(int a, b){
  // logical error as we needed to display a but we displayed c
  c = a + b;
  cout<< "Value of a" << c << endl;
}
int main(){
  // integer
  int a = 1;
  int x;
  // pointer
  int *pointerA = &a;
  // more precise than float
  double fraction = 1.192921311;
  // less precise
  float notPrecise = 1.1;
  // character
  char b = 'b';
  // names
  string name = "Jared";
  // yes or no
  bool notTrue = false;
  // fixed size
  const int SIZE = 5;
  cout<< "Enter number: ";
  cin>> x;
  cout<< "Integer: " << a << endl;
  cout<< "Pointer of a: " << pointerA << endl;
  cout<< "More precise decimals: " << fraction << endl;
  cout<< "Not as precise decimals: " << notPrecise << endl;
  cout<< "Character: " << b << endl;
  cout<< "String: " << name << endl;
  cout<< "False: " << notTrue << endl;
  cout<< "Fixed size: " << SIZE << endl;
  // syntax error
  cout<< "Hello World" << endl

  return 0;
}
