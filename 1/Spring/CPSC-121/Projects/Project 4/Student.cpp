// Written by Jared Dyreson
// File: Student.cpp
// Define all of the functions with their use-cases

#include "Student.hpp"
#include <iostream>
#include <string>
using namespace std;

Student:: Student(){}
string Student:: getName(){ return name; }
void Student:: setName(string n){
  name = n;
}
int Student:: getScore() { return score; }
void Student:: setScore(int s){
  score = s;
}
Student:: ~Student(){}
