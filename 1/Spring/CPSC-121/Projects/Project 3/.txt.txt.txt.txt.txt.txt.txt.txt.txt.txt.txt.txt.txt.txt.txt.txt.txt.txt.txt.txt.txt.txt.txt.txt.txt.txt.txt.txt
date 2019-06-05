#pragma once
// From Google : "In the C and C++ programming languages, #pragma once is a non-standard but widely supported preprocessor directive designed to cause the current source file to be included only once in a single compilation."
// #ifndef STUDENT
// #define STUDENT
class Student{
  int year = 2008;
public:
  int getYear();
  void setYear(int theYear);
};
// #endif
