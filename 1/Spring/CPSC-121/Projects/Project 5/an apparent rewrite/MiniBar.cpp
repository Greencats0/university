#include "CustomerBill.hpp"
#include "MiniBar.hpp"

// MiniBar bar;
// void MiniBar:: getBeer(CustomerBill &cbill) { int total = cbill.getTotalCharges(); total+=2; cbill.updateCharges(total); }
// void MiniBar:: getCandy(CustomerBill &cbill) { int total = cbill.getTotalCharges(); total+=1; }
void MiniBar:: updateBill(int charge, CustomerBill &cbill) { int total = cbill.getTotalCharges(); cbill.updateCharges(total+=charge); }
