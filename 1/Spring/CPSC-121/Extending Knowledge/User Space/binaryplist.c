#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void printHeader(int argc,char *argv[]);

int main(int argc, char *argv[])
{
    // this is where I got the skeleton code ------> https://stackoverflow.com/questions/23299815/magic-number-in-files-c-programming

    if (argc < 2) {
      printf("Usage: binaryplist [file]\n");
      return 1;
	}
  printHeader(argc, argv);

    return 0;
}

void printHeader(int argc, char *argv[]){
  // we open the file for inspection
  FILE* f = fopen(argv[1], "r");
  if (!f) {
    if (errno == ENOENT){
      printf("File does not exist\n");
      exit(1);
    }
  }
  char *array;
  size_t fSize;

  // three arguments are given, "f" which is the file denoted at the top of the program, "0" which is the offset, and SEEK_END which is when we want to stop I ASSUME
  fseek(f , 0 , SEEK_END);
  // the file size is equal to current position in the stream of the file denoted above
  fSize = ftell(f);
  // goes back to the top of the stream
  rewind(f);
  // this array is a char with memory allocated as big as the file plus one
  array = (char *)malloc(fSize+1);
  // read data from an array in a stream; we're gonna read the array denoted above us
  fread(array, sizeof(char), 8, f); // the size is as big as the nmemb and the last argument is the file
  // we are going to print the results, the first 2 hexidecimal places
  for(int i = 0; i < 8; i++){
    if(i == 7){
      printf("%c\n", array[i]);
    }
    else{
      printf("%c", array[i]);
    }
  }
  // printf("%02hhx%02hhx%02hhx%02hhx\n", array[0], array[1], array[2], array[3]);
  // now we do not need this array anymore, so we free it up from memory
  free(array);
}
