// Written by Jared Dyreson
// File : RoomService.hpp
// Goal : Skeleton code for the RoomService class
#pragma once
#include "CustomerBill.hpp"

class RoomService{
  private:
    const int customerBags = 5, tacosToDoor = 10, cleanRoom = 20;
  public:
    const int cleanTheRoom();
    const int bringTacos();
    const int bringCustomerBags();
    void updateCost(int charges, CustomerBill *bill);
};
