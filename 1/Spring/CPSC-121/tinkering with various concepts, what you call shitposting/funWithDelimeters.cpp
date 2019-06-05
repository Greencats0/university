/* Extract all integers from string */
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int extractInts(){
  // where are we in the streem
  streampos begin, end;
  string line, temp;
  const int STUDENTCOUNT = 4;
  string nameArray[STUDENTCOUNT] = {};
  ifstream myFile("./CPSC121data");
  if (myFile.is_open()){
    while (getline(myFile, line)){
      string studentName, studentLastName;
      int scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive, scoreSix;
      line.erase(remove(line.begin(), line.end(), ','), line.end());
      line.erase(remove(line.begin(), line.end(), '$'), line.end());
      stringstream ss(line);
      ss >> studentName >> studentLastName >> scoreOne >> scoreTwo >> scoreThree >> scoreFour >> scoreFive >> scoreSix;
      replace(studentLastName.begin(), studentLastName.end(), ',', ' ');
      string fullName = studentName + " " + studentLastName;
      int total = scoreOne + scoreTwo + scoreThree + scoreFour + scoreFive + scoreSix;
      cout<< fullName  << " " << total << " " << endl;
    }
  }
  //ss >> studentName >> scoreOne >> scoreTwo >> scoreThree >> scoreFour >> scoreFive >> scoreSix;
}

int main(){
    extractInts();
    return 0;
}

/*
string studentName, studentLastName;
int scoreOne, scoreTwo, scoreThree, scoreFour, scoreFive, scoreSix;
stringstream ss(line);
ss >> studentName >> studentLastName >> scoreOne >> scoreTwo >> scoreThree >> scoreFour >> scoreFive >> scoreSix;
replace(studentLastName.begin(), studentLastName.end(), ',', ' ');
string fullName = studentName + " " + studentLastName;
int total = scoreOne + scoreTwo + scoreThree + scoreFour + scoreFive + scoreSix;
if (studentName != "$"){
  cout<< fullName << endl;
  cout<< total << endl;
}
*/
