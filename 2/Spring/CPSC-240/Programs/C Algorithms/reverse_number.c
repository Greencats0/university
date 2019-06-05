#include <stdio.h>

void reverse_number(int number){
  while(number != 0){
    printf("%i", number%10);
    number = number/10;
  }
}

int main(){
  reverse_number(67);
  printf("\n");
  return 0;
}
