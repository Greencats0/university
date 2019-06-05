// Midterm prep
// Written by Jared Dyreson
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Car{
  private:
    int speed;
    string name;
    string color;
  public:
    Car() { cout << "Lol i am a constructor when I create an object" << endl; } ;
    void setColor(string c){ color = c; }
    string getColor() { return color; }
    void setSpeed(int s) { speed = s; }
    int getSpeed() { return speed; }
    void setName(string n) { name = n; }
    ~Car() { cout << "LOLZ get wrecked" << endl; } ;
};

struct Student{
  string name = "NULL";
  int ID = 0;
};

// just to remove clutter
void clear(){ cout << "\033[2J\033[1;1H"; }

// global variable
const int GLOBAL = 10;

// arrays
void createArray(){
  // an array of constant size
  const int SIZE = 5;
  int scores[SIZE] = {0};
  for(int i = 0; i < 5; i++){
    cout << scores[i] << endl;
  }
}

void printingFileViaReference(ifstream &stream){
  string line;
  while(getline(stream, line)){
    cout << line << endl;
  }
}

void demostratingLocalAndGlobalVariables(){
  int GLOBAL = 0;
  cout << "Variable inside demostratingLocalAndGlobalVariables is: " << GLOBAL << endl;
}

void demonstratingStatic(){
  static int var = 9;
  var++;
  cout << var << endl;
}

void defaultArguments(string hello="Hello", int size=10){
  cout << "This function has two arguments <defaultArguments>" << endl;
  cout << "First argument is a string variable: " << hello << endl;
  cout << "Second argument is an integer variable: " << size << endl;
}

void overLoaded(string overloadedstring, int size){
  cout << overloadedstring << endl;
  cout << size << endl;
}

int overLoaded(int size){
  int sum = 10;
  return sum+=size;
}

void printMenu(){
  cout << "" << endl;
}

int main(){
  createArray();
  cout << "Global variable is " << GLOBAL << endl;
  demostratingLocalAndGlobalVariables();
  ifstream stream;
  stream.open("readMePlease.txt");
  string line;
  while(getline(stream, line)){
    cout << line  << endl;
  }
  stream.seekg(0, ios::beg);
  printingFileViaReference(stream);
  stream.close();
  demonstratingStatic();
  demonstratingStatic();
  defaultArguments("hello", 12);
  cout << "Size of Car class " << sizeof(Car) << endl;
  Car car;
  car.setColor("Red");
  cout << car.getColor() << endl;
  int size = 10;
  int *array = new int[size];
  for(int i = 0; i < size; i++){
    array[i] = 0;
  }
  for(int i = 0; i < size; i++){
    cout << array[i] << endl;
    cout << *(array + 1) << endl;
  }
  delete [] array;
  array = nullptr;
  Student student;
  student.ID = 100;
  cout << student.ID<< endl;
  // such an odd way of assigning a string variable but it actually works....
  string s("Hello");
  return 0;
}
