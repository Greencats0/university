#include <iostream>
#include <string>
using namespace std;

int main() {
  char choice; int num;
  cin >> choice; // Suppose user enters B
  cin >> num; // Suppose user enters 5
  if (choice =='A') {
    cout << "1";
  }

  else if (choice == 'B') {
    cout << "2";
    if (num > 5) {
      cout << "A";
    }
  cout << "0";
  if (num <= 5) {
    cout << "C";
  }

  }
}
