#include <iostream>
#include <string>
using namespace std;

int main() {
  // ask for your name and let's assume it is your full name
  string yourName;
  cout<<"What is your name? \n";
  getline(cin, yourName);

  // since the address was supplied, we store it as a variable
  string yourAddress = "800 N.State College Fullerton CA 92831";

  // since the phone number was also provided, we store it as a variable
  // since there would be a conflict between strings for hyphens and parenthesis, I will omit them and store yourPhoneNumber as an int

  // this is how I will declare large integers
  unsigned long long veryLongAndScaryNumber = 6572782200;

  // it does not matter if each char is properly treated as a char or int as we just treat it as a string
  string yourPhoneNumber = "(657)278-2200";

  // ask for your major
  string yourCollegeMajor;
  cout<<"What is your major \n";
  getline(cin, yourCollegeMajor);

  // now we have all of the information, let us print it all out...dare I say..cout?
  cout<<"Your name is " << yourName << '\n';
  cout<<"Your predefined address is " << yourAddress  << '\n';
  cout<<"Your predefined phone number is " << yourPhoneNumber << '\n';
  cout<<"Lastly, you are enrolled at CSUF as a " << yourCollegeMajor << " major" << '\n';

  return 0;
}
