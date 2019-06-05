// Written by Jared Dyreson
// File: Student.hpp
// Initialize Student class with given attributes and functions
#pragma once
#include <string>
using namespace std;
class Student{
  private:
    string name;
    int score, amount;
    // huh, put the array as a mutable object inside the class attributes....
    // if I didn't, I would then need to Initialize it inside of main in Source.cpp and completely defeats the purpose!
    string *names;
    int *scores;
  public:
    void setScore(int s);
    int getScore();
    void setName(string n);
    string getName();
    Student();
    ~Student();
};
