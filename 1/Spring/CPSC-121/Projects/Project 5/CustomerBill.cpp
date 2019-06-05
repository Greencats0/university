// Written by Jared Dyreson : Project Five -> Hotel Manager
// File : CustomerBill.cpp
// Goal : Define all functions for the CustomerBill class
#include <iostream>
#include <string>
#include "CustomerBill.hpp"

using namespace std;

void CustomerBill:: setCustomerName(string n){ customerName = n; }
string CustomerBill:: getCustomerName(){ return customerName; }
void CustomerBill:: setCustomerCharges(size_t c) { customerCharges = c; }
size_t CustomerBill:: getCustomerCharges(){ return customerCharges; }
void CustomerBill:: setCustomerStayTime(int d){ numberOfDaysStayed = d; }
int CustomerBill:: getCustomerStayTime(){ return numberOfDaysStayed; }
double CustomerBill:: getCustomerTax() { return tax; }
