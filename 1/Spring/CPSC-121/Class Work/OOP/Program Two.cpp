#include <iostream>
#include <string>

using namespace std;

class Student {
  double GPA;
  string name;
public:
  double getGPA() { return GPA; }
  void setGPA(double gpa) {GPA = gpa;}
  string getName() { return name; }
  void setName(string n) { name = n; }
};

int main(){
  Student studentOne;
  studentOne.setGPA(4.0);
  studentOne.setName("Levi");
  cout << studentOne.getName() << endl;
  cout << studentOne.getGPA() << endl;
  return 0;
}
