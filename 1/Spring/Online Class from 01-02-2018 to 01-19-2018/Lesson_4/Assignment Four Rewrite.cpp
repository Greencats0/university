// Assignment 5 written by 2spoopyforyou
#include <iostream>
#include <string>
using namespace std;

enum operand {Addition = 1, Subtraction, Multiplication, Division, Modulous};

int main() {
  // list the available operations
  // change selection to char as it will allow us to more easily implement an escape Q
  // give it a while loop so it can run until it is terminated
  char selection;
  while (selection != 'Q') {
    cout<< '\n';
    cout<< "These are the available math operands available\n";
    cout<< '\n';
    cout<< "A) Addition: +\n";
    cout<< "B) Subtraction: -\n";
    cout<< "C) Multiplication: *\n";
    cout<< "D) Division: /\n";
    cout<< "E) Modulous: %\n";
    cout<< "Q) Quit\n";
    cout<< '\n';
    cout<< "Please select your option: ";
    cin >> selection;

    switch(selection){

      int numberOne;
      int numberTwo;
      cout<< "Numbers can only be from 1 to 20\n";
      cout<< "Please enter number one: ";
      cin >>  numberOne;
      while (numberOne > 20){
        cerr<< "Number is too big, please try again: ";
        cin >> numberOne;
      }
      cout<< "Please enter number two: ";
      cin >> numberTwo;
      while (numberTwo > 20){
        cerr<< "Number is too big, please try again: ";
        cin >> numberTwo;
      }
      case 'A':
      {
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
        break;
      }

      case 'B':
      {
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
        break;
      }

      case 'C':
      {
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
        break;
      }

      case 'D':
      {
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
        break;
      }

      case 'E':
      {
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
        break;
      }
      case 'Q':
      {
        cout<< "Quiting...\n";
        break;
      }
      default:
      {
        cerr<< "Sorry, that is an invalid option\n";
        cerr<< '\n';
        cerr<< "Go to top of list\n";
        continue;
      }
    }
  }
}
