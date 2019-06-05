#include <stdio.h>
int cvtEndian(int x){
  int y = 0;
  y = (x >> 24) & 0x000000FF;
  y = y | ((x >> 8) & 0x0000F00);
  y = y | ((x << 8) & 0x00FF0000);
  y = y | ((x  << 24) & 0xFF000000);
  return y;
}
/*
  ; r11 is the x value
  ; r12 is the y value
  ; r13 is a copy of the y value
  shr r11, 24
  and r11, 0x000000FF
  mov r12, r11
  mov r13, r12 ; storing the temp value so we can manipulate y
  shr r11, 8

*/
int main(){
  int x = 19;
  printf("%d\n", x);
  printf("%d\n", cvtEndian(x));
  return 0;
}
