// Written by Jared Dyreson
#include <string>
using namespace std;
#pragma once
class CustomerBill{
  private:
    string customerName;
    int timeStayed;
    int totalCharges = 0;
  public:
    void setName(string n);
    string getName();
    void setTimeStayed(int t);
    int getTimeStayed();
    void updateCharges(int newCharges);
    int getTotalCharges();
};
