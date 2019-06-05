// this is an example program of using pointers
// level: basic
#include <iostream>
using namespace std;

int main(){
  int a;
  int b;
  int *ptrA;
  int *ptrB;
  cout<< "A: ";
  cin>> a;
  cout<< "B: ";
  cin>> b;
  ptrA = &a;
  ptrB = &b;
  cout<< "The value of a is " << a << " and it's position in memory is " << ptrA << endl;
  cout<< "The value of b is " << b << " and it's position in memory is " << ptrB << endl;
  return 0;
}
