#include <iostream>
#include <string>
using namespace std;

int main() {

  int e, f, g;
  e = 1;
  f = 2;
  g = 3;
  e = e/(f - g);
  cout << e << '\n';

  e /= (f + g);

  cout << e << '\n';

  int x = 0;

  x--;

  --x;

  int y =x++;
  cout << "Value of x: " << x << '\n';
  cout << "Value of y: " << y << '\n';

  return 0;
}
