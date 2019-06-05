// Written by Jared Dyreson
// File : MiniBar.cpp
// Goal : Define the charges for a given item in the hotel services
#include "CustomerBill.hpp"
#include "RoomService.hpp"
#include "MiniBar.hpp"

const int MiniBar:: buyAlcohol() { return alchol; }
// $12 for alcohol
const int MiniBar:: buyCandy() { return candy; }
// $2 for candy
const int MiniBar:: buyWater() { return water; }
// $10 for water
void MiniBar:: updateCost(int charge, CustomerBill *bill) {bill->setCustomerCharges(bill->getCustomerCharges()+charge); }
