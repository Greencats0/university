// Written by Jared Dyreson
// Inspired by this post on StackOverflow => https://stackoverflow.com/questions/9579930/separating-class-code-into-a-header-and-cpp-file
// This is full of prototypes, the gut functionality is implemented in airplanes.cpp
// Header file: airplane.h
#pragma once
// clang was giving a warning using pragma once, it preferred ifndef. Still compiled without any errors
#include <string>
using namespace std;

class airplane{
  private:
    // all of it's attributes
    string model;
    int year, speed, capactity = 0;
public:
  // all functions to be used by class airplane
  string getModel();
  void setModel (string m);
  int getSpeed();
  void setSpeed(int s);
  int getYear();
  void setYear(int y);
  int getCapacity();
  void setCapacity (int c);
  int accelerate(int s);
  int brake(int s);
  // constructor
  airplane();
  // destructor
  ~airplane();
};
