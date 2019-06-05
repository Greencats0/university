#include "Student.h"
#include <iostream>
using namespace std;
int main(){
  Student s;
  cout << s.getYear();
  cout << endl;
  int y;
  cout << "Enter Year: ";
  cin >> y;
  s.setYear(y);
  cout << endl;
  cout << s.getYear() << endl;

}
