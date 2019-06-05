#include <iostream>
#include <string>
using namespace std;

enum operand {Addition = 1, Subtraction, Multiplication, Division, Modulous};

int main() {
  // list the available operations
  int selection;
  cout<< "These are the available math operands available\n";
  cout<< '\n';
  cout<< "1) Addition: +\n";
  cout<< "2) Subtraction: -\n";
  cout<< "3) Multiplication: *\n";
  cout<< "4) Division: /\n";
  cout<< "5) Modulous: %\n";
  cout<< '\n';
  cout<< "Please select your option: ";
  cin >> selection;

  int numberOne;
  int numberTwo;
  cout<< "Numbers can only be from 1 to 20\n";
  cout<< "Please enter number one: ";
  cin >>  numberOne;
  if (numberOne > 20){
    cout<< "Number is too big, please try again: ";
    cin >> numberOne;
  }
  cout<< "Please enter number two: ";
  cin >> numberTwo;
  if (numberTwo > 20){
    cout<< "Number is too big, please try again: ";
    cin >> numberTwo;
  }
  cout<< "Your numbers are " << numberOne << " and " << numberTwo << '\n';
  if (selection == 1) {
    int sum = numberOne + numberTwo;
    int userSum;
    cout<< "Your turn; the sum of " << numberOne << " + " << numberTwo << " is: ";
    cin >> userSum;
    if (sum == userSum){
      cout<< "Correct!\n";
    }
    else {
      cerr<< "Sorry, the correct answer is " << sum << '\n';
    }
  }
  else if (selection == 2)  {
    int difference = numberOne - numberTwo;
    int userDifference;
    cout<< "Your turn; the difference of " << numberOne << " - " << numberTwo << " is: ";
    cin >> userDifference;
    if (difference == userDifference){
      cout<< "Correct!\n";
    }
    else {
      // my IDE's completion gave me this idea, was able to filter out the output from ./testing_stdout 2> /dev/null and nothing came out cause the error was filtered out mind blown
      cerr<< "Sorry, the correct answer is " << difference << '\n';
    }
  }
  else if (selection == 3) {
    int product = numberOne * numberTwo;
    int userProduct;
    cout<< "Your turn; the product of " << numberOne << " * " << numberTwo << " is: ";
    cin >> userProduct;
    if (product == userProduct){
      cout<< "Correct";
    }
    else {
      cerr<< "Sorry, the correct answer is " << product << '\n';
    }
  }
  else if (selection == 4) {
    int quotient = numberOne / numberTwo;
    int userQuotient;
    cout<< "Your turn; the quotient of " << numberOne << " / " << numberTwo << " is: ";
    cin >> userQuotient;
    if (quotient == userQuotient){
      cout<< "Correct!\n";
    }
    else {
      cerr<< "Sorry, the correct answer is " << quotient << '\n';
    }
  }
  else if (selection == 5) {
    int modulous = numberOne % numberTwo;
    int userModulous;
    cout<< "Your turn; the modulous of " << numberOne << " * " << numberTwo << " is: ";
    cin >> userModulous;
    if (modulous == userModulous){
      cout<< "Correct!\n";
    }
    else {
      cerr<< "Sorry, the correct answer is " << modulous << '\n';
    }
  }
  else {
    cerr<< "Unknown operand\n";
    return 1;
  }
  return 0;
}
