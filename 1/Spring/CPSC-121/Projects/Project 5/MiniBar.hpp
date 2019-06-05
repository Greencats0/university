// Written by Jared Dyreson
// File : MiniBar.hpp
// Goal : Skeleton code for the MiniBar class
#pragma once
#include "CustomerBill.hpp"
#include "RoomService.hpp"

class MiniBar{
  private:
    const int water = 2, alchol = 10, candy = 3;
  public:
    const int buyAlcohol();
    const int buyCandy();
    const int buyWater();
    void updateCost(int charge, CustomerBill *bill);
};
