#include "CustomerBill.hpp"
#include "MiniBar.hpp"
#include <string>
#include <iostream>

using namespace std;

int main() {
  CustomerBill bill;
  MiniBar bar;
  string customerName;
  cout << "Enter customer name: ";
  getline(cin, customerName);
  bill.setName(customerName);
  //bar.updateBill(bar.getBeer(), bill);
  cout << bar.getCandy() << endl;
  bar.updateBill(bar.getCandy(), bill);
  cout << bill.getTotalCharges() << endl;
  cout << bar.getWater() << endl;
  bar.updateBill(bar.getWater(), bill);
  cout << bill.getTotalCharges() << endl;
}
