#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
  ofstream outputFile;
  const int SIZE = 3;
  string nameOne, nameTwo, nameThree;
  int ageOne, ageTwo, ageThree;
  outputFile.open("FriendsManifesto.txt");
  cout<< "Friends List: " << endl;
  cout<< "Name of friend one: ";
  cin >> nameOne;
  cout << "Age of friend one: ";
  cin >> ageOne;
  cout << "Name of friend two: ";
  cin >> nameTwo;
  cout << "Age of friend two: ";
  cin >> ageTwo;
  cout << "Name of friend three: ";
  cin >> nameThree;
  cout << "Age of friend three: ";
  cin >> ageThree;
  outputFile << nameOne  << " " << ageOne << endl;
  outputFile << nameTwo  << " " << ageTwo << endl;
  outputFile << nameThree << " " << ageThree << endl;
  outputFile.close();
  return 0;
}
