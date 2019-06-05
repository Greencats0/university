// variables
#include <iostream>
#include <string>
using namespace std;

int main() {
  // when you declare a variable, you start with the data type , then it's name, equal sign to show that the variable is equal to something then the value of the varible. End the statement with a semicolon as it is a marker for the complier.
  int age = 18;
  //most common data type
  int score;

  // the difference between int and char is that int can only store integers/numbers and char can only store single a character/letter

  // char -> character needs a single quotation mark
  char grade = 'B';

  // bool -> boolean can only store two values, true or false
  bool found = true;
  bool lost = false;

  // floats allow us to store decimal values. It is limited to 8 numbers after the dot
  float amount = 4.56;

  // the difference between the two is how precise the decimal value is


  // double allows us to have a more precise value, up to 16 numbers after the dot because it is <double> the precision
  double value = 45.47;

  string name = "John Smith";
  // last, variables are case sensitive
  string gender = "Boy";
  string Gender = "Girl";
  // this is allowed because the name is in a different case

}
