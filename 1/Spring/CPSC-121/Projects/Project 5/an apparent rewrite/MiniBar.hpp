// Written by Jared Dyreson
#include "CustomerBill.hpp"
#pragma once
class MiniBar{
  private:
    int water, candy, beer;
  public:
    MiniBar() { water = 1; candy = 2; beer = 5; }
    int getWater() { return water; }
    int getCandy() { return candy; }
    int getBeer() { return beer; }
    void updateBill(int charge, CustomerBill &cbill);
};
