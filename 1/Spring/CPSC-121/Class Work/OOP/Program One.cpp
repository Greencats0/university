#include <iostream>
#include <string>

using namespace std;

struct Employee{
  int employeeNumber;
  string name;
};

int main(){
  Employee empl;
  empl.employeeNumber=1234;
  empl.name="John";
  cout << empl.name << "'s" << " id is " << empl.employeeNumber << endl;
  return 0;
}
