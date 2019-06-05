#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
  const int SIZE = 2;
  string names[SIZE] = {"Jared Dyreson", "Helena Cuellar"};
  char grades[SIZE] = {'A', 'A'};
  for (int i = 0; i < SIZE; i++){
    cout << "Name: " << names[i] << endl;
    cout << "Grade: " << grades[i] << endl;
  }
  return 0;
}
