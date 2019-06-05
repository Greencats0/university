#include <stdio.h>
#include <stdlib.h>

unsigned char read_in_file(){
  FILE *fp;
  fp = fopen("packet", "rb");
  fseek(fp, 0L, SEEK_END);

  unsigned long int size = ftell(fp);

  rewind(fp);

  // unsigned char buffer[size];
  // Explicit type cast -> https://stackoverflow.com/questions/5099669/invalid-conversion-from-void-to-char-when-using-mallocs
  unsigned char *buffer = (unsigned char*)malloc( sizeof(unsigned char) * ( size + 1 ) ); // https://stackoverflow.com/questions/3115564/allocating-char-array-using-malloc
  fread(&buffer, 1, 1, fp);
  fclose(fp);
  return *buffer;
  // return dynamically allocated array in C/C++ -> https://stackoverflow.com/questions/44478449/c-how-to-return-dynamically-allocated-array-from-function
}

int size_of_packet(){
  FILE *fp;
  fp = fopen("packet", "rb");
  fseek(fp, 0L, SEEK_END);

  unsigned long int size = ftell(fp);
  fclose(fp);
  return size;
}
