#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
  char *s;
  s = strdup("Holberton");
  if (s == NULL){
    fprintf(stderr, "Cannot allocate memory with malloc\n");
    return(EXIT_FAILURE);
  }
  printf("%p\n", (void *)s);
  return(EXIT_SUCCESS);
}
