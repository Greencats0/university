// Written by Jared Dyreson

#include <iostream>
#include <string>
using namespace std;

void helpMenu();
int main(){
  char input = '\0';
  do{
    helpMenu();
    cout << "Input: ";
    cin.get(input);
    switch(input){
      case '1': {
        cout << "it is!" << endl;
        break;
      }
    }
    input = '\0';
  } while(input != 'Q');
  return 0;
}

void helpMenu(){
  cout << "Debugging the printer" << endl;
  cout << "1) Is the printer communicating with the computer? If not, turn on." << endl;
  cout << "2) Clear all print jobs sent to computer" << endl;
  cout << "3) List all print jobs" << endl;
}
