// Written by Jared Dyreson
// File : Source.cpp
// Goal : Implementation

#include "CustomerBill.hpp"
#include "RoomService.hpp"
#include "MiniBar.hpp"
#include <string>
#include <iostream>
using namespace std;

// Prototypes
int numDaysStayed();
string customerName();
bool usedMiniBar();
bool usedRoomService();
void clear();

int main(){
  const double tax = 1.0825;
  // create three instances, each for their respective class
  CustomerBill customer;
  RoomService roomService;
  MiniBar miniBar;
  // getting and setting name
  string name = customerName();
  customer.setCustomerName(name);
  // getting and setting time stayed
  int numberOfDaysStayed = numDaysStayed();
  // getting, calculating and setting the amount it cost for board
  int costToStay = numberOfDaysStayed*100;
  customer.setCustomerCharges(costToStay);
  customer.setCustomerStayTime(numberOfDaysStayed);
  // let's see if they used the minibar
  char selection = '\0';
  do{
    clear();
    cout << "Which items did you use?" << endl;
    cout << "1) Water" << endl;
    cout << "2) Candy" << endl;
    cout << "3) Alcohol" << endl;
    cout << "Q) Quit" << endl;
    cout << "Option: ";
    cin >> selection;
    switch(selection){
      case 1: {
        miniBar.updateCost(miniBar.buyWater(), &customer);
        break;
      }
      case 2: {
        miniBar.updateCost(miniBar.buyCandy(), &customer);
        break;
      }
      case 3: {
        miniBar.updateCost(miniBar.buyAlcohol(), &customer);
        break;
      }
      case 'Q': {
        clear();
        break;
      }
      default: {
        cerr << "[*] Invalid option" << selection << endl;
      }
    }
  } while (selection != 'Q');
  selection = '\0';

  do{
    clear();
    cout << "Which services did you use?" << endl;
    cout << "1) Bags brought to the door" << endl;
    cout << "2) Brought tacos" << endl;
    cout << "3) Cleaned the room" << endl;
    cout << "Q) Quit" << endl;
    cout << "Option: ";
    cin >> selection;
    switch(selection){
      case 1: {
        roomService.updateCost(roomService.bringCustomerBags(), &customer);
        break;
      }
      case 2: {
        roomService.updateCost(roomService.bringTacos(), &customer);
        break;
      }
      case 3: {
        roomService.updateCost(roomService.cleanTheRoom(), &customer);
        break;
      }
      case 'Q':{
        clear();
        break;
      }
      default: {
        cerr << "[*] Invalid option" << endl;
      }
    }
  } while (selection != 'Q');
  // let's generate a tab that is easier for the customer to interpret
  cout << "Thank you for staying at Jared 5 Star Resort" << endl;
  cout << "+---------+" << endl;
  cout << "| Receipt |" << endl;
  cout << "+---------+" << endl;
  cout << "Nights stayed: " << customer.getCustomerStayTime() << endl;
  // total amount with tax factored in
  cout << "Total Amount due: " << (customer.getCustomerCharges() * customer.getCustomerTax()) << endl;
  // since nothing was dynamically allocated, the stack will be cleared for us automatically
  return 0;
}


int numDaysStayed(){
  int num;
  cout << "How many nights did you stay?: ";
  cin >> num;
  return num;
}

string customerName(){
  string name;
  cout << "Your name?: ";
  getline(cin, name);
  return name;
}

bool usedMiniBar(){
  bool miniBarFlag = false;
  cout << "Did you use the mini bar?[0/1]: ";
  cin >> miniBarFlag;
  return miniBarFlag;
}

bool usedRoomService(){
  bool usedRoomServiceFlag = false;
  cout << "Did you request for room service during your stay?[0/1]: ";
  cin >> usedRoomServiceFlag;
  return usedRoomServiceFlag;
}
void clear() { cout << "\033[2J\033[1;1H"; }
