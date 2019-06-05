// Written by Jared Dyreson
// File : RoomService.cpp
// Goal : Define the functions for the RoomService class
#include "CustomerBill.hpp"
#include "RoomService.hpp"

const int RoomService:: cleanTheRoom() { return cleanRoom; }
const int RoomService:: bringCustomerBags() { return customerBags; }
const int RoomService:: bringTacos() { return tacosToDoor; }
void RoomService:: updateCost(int charges, CustomerBill *bill) { bill->setCustomerCharges((bill->getCustomerCharges()+charges));}
