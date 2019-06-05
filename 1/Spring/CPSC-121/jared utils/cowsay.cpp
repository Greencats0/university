#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void cowsay(string whatISay){
  int stringlength = strlen(whatISay.c_str());
  cout << "+";
  for (int i = 0; i < stringlength; i++){
    cout<< "-";
  }
  cout << "+" << endl;
  cout << "|" << whatISay << "|" << endl;
  cout << "+";
  for (int i = 0; i < stringlength; i++){
    cout<< "-";
  }
  cout << "+" << endl;
}
int main(){
  cowsay("Jared");
  return 0;
}
