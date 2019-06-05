#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;

int removeDuplicates(const int size, string names[]){
  int prev = 0;
  for (int i = 0; i < size; i++){
    if (names[i] != names[prev]){
      names[++prev] = names[i];
    }
  }
  int count = prev + 1;
  return count;
}
int main(){
  const int SIZE = 5;
  string names[SIZE] = {"Jared Dyreson", "Helena Cuellar", "Jared Dyreson", "Helena Cullear", "Gabe Ball"};
  sort(&names[0], &names[SIZE]);
  // these are my notes on size_t as I am trying to process it all
  // int and unsigned int are 32 bits
  // size_t is a datatype that allows us to store an unsigned int of 64 bit size
  // for reference, an unsigned int is a value (integer) that allows us to store negative numbers up to a big number [postive, negative or zero]
  // so basically we are saying that size_t replaces int for an unconstrained size
  int count = removeDuplicates(SIZE, names);
  for (int j = 0; j < count; j++){
    printf("names[%d] = %s\n", j, names[j].c_str());
  }
  return 0;
}
