#include <iostream>
#include <string>
using namespace std;

int main() {
  // declare the variable
  int number;
  // ask for user input
  cout<<"Gimme your number girl\n";
  cin >> number;
  // Repeat back what the user inputed
  cout << "You entered " << number << '\n';

  // another data type such as char
  char grade;
  cout<<"Your grade for computer science\n";
  cin >> grade;
  cout << "You currently have an " << grade << " in this Computer Science Class"<< '\n';

  // using string and this is only good for name that is does not have a space in it because it is a limitation of cin
  string name;
  cout<<"What is your name?\n";
  cin.ignore();
  getline(cin, name);
  cout << "Your name is " << name << '\n';

  // to bypass this restriction, we must use getLine to capture everything from cin
  string newName;
  cout<<"Enter your name.\n";
  // this is used because we need to flush out the stream that cin is looking for when the input has a space in it
  // if we do not do this, getline will see the cout is left with a dangling '\n' or newline in the buffer. This will then confuse getline and will then be considered the input and that is not what we intended to happen
  cin.ignore();
  getline(cin, newName);
  cout << "Your full name is " << newName << '\n';

  // now let us dabble in the art of decimals, really glad computers can do math so I don't have to
  double decimalValue;
  cout<<"Gimme your decimals\n";
  cin >> decimalValue;
  cout << "Decimal value was " << decimalValue << '\n';
  return 0;
}
