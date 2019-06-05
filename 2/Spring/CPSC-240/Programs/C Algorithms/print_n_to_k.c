#include <stdio.h>

void print_range(int s, int e, int* array){
  for(int i = s; i < e; ++i){
    printf("%i", array[i]);
  }
}
int main() {
  int array[180] = {0};
  print_range(128, 179, array);
  printf("\n");
  return 0;
}
