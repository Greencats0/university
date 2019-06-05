// Creating a int array

#include <stdio.h>

#define arraySize(array) (int)(sizeof(array)) / (int)sizeof(array[0])

int main(){
  int array[10] = {0};
  printf("%d\n", arraySize(array));
  // for(size_t i = 0; i < arraySize(array); i++){
  //   printf("%d\n", array[i]);
  // }
  printf("%d\n", array[9]);
}
