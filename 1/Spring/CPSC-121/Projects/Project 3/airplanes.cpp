// Written by Jared Dyreson
// File : airplanes.cpp
// This is where we place all of the guts of the functions so we do not have to include it in the header file
// Think of this file as the middle man between the actual code and the header file
// end goal, make code clean and minimal
#include "airplanes.h"
#include <iostream>
#include <string>
using namespace std;

airplane:: airplane(){
  cout << "Welcome to Jared Airlines" << endl;
}
string airplane:: getModel() { return model; }
void airplane:: setModel(string m){
  // make sure the variable name you want to return comes first, the compliler will be like "oops, you didn't specify" and be a jerk
  model = m;
}
int airplane:: getSpeed() { return speed; }
// pass the input as reference to retain value
void airplane:: setSpeed(int s){
  speed = s;
}
int airplane:: getYear() { return year; }
void airplane:: setYear(int y){
  year = y;
}
int airplane:: getCapacity() { return capactity; }
void airplane:: setCapacity(int c){
  capactity =  c;
}
int airplane:: accelerate(int s){
  // increase the speed by 100
  return speed+=100;
}
int airplane:: brake(int s){
  // decrease the speed by 100
  return speed-=100;
}
airplane:: ~airplane(){
  // fun fact, you can't overload a destructor. No parameters, no problems!
  cout << "Thank you for flying!" << endl;
}
