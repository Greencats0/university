#include <iostream>
#include <string>
using namespace std;

void sayHello(string name);
string getName();

int main(){
  string firstName = getName();
  sayHello(firstName);
  return 0;
}

void sayHello(string name){
  cout<< "hello " << name << endl;
}

string getName(){
  string userInput;
  cin >> userInput;
  return userInput;
}
