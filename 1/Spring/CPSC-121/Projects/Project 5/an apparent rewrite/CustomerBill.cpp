#include "CustomerBill.hpp"
#include <string>
using namespace std;

void CustomerBill:: setName(string n) { customerName = n; }
string CustomerBill:: getName() { return customerName; }
void CustomerBill:: setTimeStayed(int t) { timeStayed = t; }
int CustomerBill:: getTimeStayed() { return timeStayed; }
void CustomerBill:: updateCharges(int newCharges) { totalCharges+=newCharges; }
int CustomerBill:: getTotalCharges() { return totalCharges; }
