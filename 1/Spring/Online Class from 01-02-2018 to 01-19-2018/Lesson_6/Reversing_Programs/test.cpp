#include <iostream>
using namespace std;

int main() {
  const int s = 10;
  int c[s] = { 1, 2, 3, 4, 5 };
  for (int j = 0; j < s; j++){
    cout<< c[j] << endl;
  }
}
