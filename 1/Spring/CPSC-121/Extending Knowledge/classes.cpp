#include <iostream>
#include <string>
#include "airplanes.h"
using namespace std;

int main(){
  // testing an object oriented project
  airplane red;
  red.model = "Boeing 747";
  red.year = 2005;
  red.speed = 1000;
  red.capactity = 300;
  cout << "Model: " << red.model << "\n" << "Year: " << red.year << "\n" << "Speed: " << red.speed << "\n" << "Maximum capactity: " << red.capactity << endl;
  return 0;
}
