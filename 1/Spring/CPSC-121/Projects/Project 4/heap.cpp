#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
  double *ptr;
  ptr = new double;
  *ptr = 5.6;
  cout << *ptr << endl;
  delete ptr;
  cout << *ptr << endl;
  // for (int i = 0; i < 3; i++){
  //   ptr = new double;
  //   srand(time(NULL));
  //   *ptr = rand() % 100 + 1;
  //   cout << *ptr << endl;
  //   delete ptr;
  //   ptr = new double;
  // }
}
