// simple pizza price calculator written by 2spoopyforyou (Jared Dyreson)
// Under the GNU General Public License (GNU GPL)
// Free for anyone to repurpose, dismantle or overhaul
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

double calculate(double diameter, double price){
  double average = diameter / price;
  return average;
}
double getSize(){
  double size;
  cin >> size;
}
double getPrice(){
  double price;
  cin>> price;
}
int main(){

  double smallDiameter, mediumDiameter, largeDiameter;
  double smallPrice, mediumPrice, largePrice;
  double calculatedSmall, calculatedMedium, calculatedLarge;
  cout<< "Small diameter: ";
  smallDiameter = getSize();
  cout<< "Small price: ";
  smallPrice = getPrice();
  cout<< "Medium diameter: ";
  mediumDiameter = getSize();
  cout<< "Medium price: ";
  mediumPrice = getPrice();
  cout<< "Large diameter: ";
  largeDiameter = getSize();
  cout<< "Large price: ";
  largePrice = getPrice();
  calculatedSmall = calculate(smallDiameter, smallPrice);
  calculatedMedium = calculate(mediumDiameter, mediumPrice);
  calculatedLarge = calculate(largeDiameter, largePrice);
  // let's give it back to them
  cout<< "Small pizza diameter " << smallDiameter << endl;
  cout<< "Price: " << smallPrice << endl;
  cout<< "Per square inch: " << calculatedSmall << endl;
  cout<< endl;

  cout<< "Medium pizza diamter: " << mediumDiameter << endl;
  cout<< "Price: " << mediumPrice << endl;
  cout<< "Per square inch: " << calculatedMedium << endl;
  cout<< endl;

  cout<< "Large pizza diameter: " << largeDiameter << endl;
  cout<< "Price: " << largePrice << endl;
  cout<< "Per square inch: " << calculatedLarge << endl;
  cout<< endl;

  // this would return lowest value with variable name with a smaller code base
  double smallest, biggest;
  // double min_double;
  // min_double = min(min(calculatedSmall, calculatedMedium), (calculatedMedium, calculatedLarge));
  // *comment in comment* - bypass all of these and go straight to the last if loops, replacing the "smallest" variable name with min_double
  if (calculatedSmall < calculatedMedium){
    smallest = calculatedSmall;
  }

  else{
    smallest = calculatedMedium;
  }
  if (calculatedMedium < smallest){
    smallest = calculatedMedium;
  }
  else {
    smallest = calculatedLarge;
  }
  if (calculatedSmall == smallest){
    cout<< "Small is best option for " << smallest << " per square inch" << endl;
    }
    else if (calculatedMedium == smallest){
      cout<< "Medium is the best option for " << smallest << " per square inch" << endl;
    }
    else if (calculatedLarge == smallest){
      cout<< "Large is the best option for " << smallest << " per square inch" << endl;
    }
  return 0;
}
