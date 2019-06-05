// Written by Jared Dyreson : Project Five -> Hotel Manager
// File : CustomerBill.hpp
// Goal : Lay the foundation for the class
#pragma once
#include <string>
using namespace std;

class CustomerBill{
  private:
    // attributes of the class
    string customerName;
    size_t customerCharges = 0;
    int numberOfDaysStayed = 0;
    const double tax = 1.0825;
  public:
    // able to be accessed by the other .cpp files
    void setCustomerName(string n);
    string getCustomerName();
    void setCustomerCharges(size_t c);
    size_t getCustomerCharges();
    void setCustomerStayTime(int d);
    int getCustomerStayTime();
    double getCustomerTax();
};
