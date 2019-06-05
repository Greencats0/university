#include <iostream>
#include <string>
using namespace std;

int getUserInput(){
  int sizeOfPizza;
  cout<< "Size: ";
  cin >> sizeOfPizza;
  return sizeOfPizza;
}

int validateSize(int sizeOfPizza){
  if (sizeOfPizza >= 5 && sizeOfPizza <= 7){
    cout<< "small";
  }
  else if (sizeOfPizza >= 8 && sizeOfPizza <=10){
    cout<< "medium";
  }
  else if (sizeOfPizza >= 11 && sizeOfPizza <= 13){
    cout<< "large";
  }
  else{
    getUserInput();
  }
}

int main(){
  int k = getUserInput();
  validateSize(k);
}








int arrayRoute(){
  const int PIZZA_SIZE = 3;
  const int PIZZA_PRICE = 3;
  const int PIZZA_PER_SQ_IN = 3;
  string size[PIZZA_SIZE] = { "Small", "Medium", "Large" };
  int price[PIZZA_PRICE] = { 0, 0, 0 };
  double perSQIn[PIZZA_PER_SQ_IN] = { 0.0, 0.0, 0.0};

  for (int a = 0; a < PIZZA_SIZE; a++){
    for (int b = 0; b < PIZZA_PRICE; b++){
      for (int c = 0; c < PIZZA_PER_SQ_IN; c++){
        cout<< "Size: " << size[a] << endl;
        cout<< "Total: " << price[b] << endl;
        cout<< "Price per square inch: " << perSQIn[c] << endl;
      }
    }
  }
}
