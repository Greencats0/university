// Written by Jared Dyreson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/*
- steps:
  - read the file into the buffer: https://stackoverflow.com/questions/51224682/read-file-byte-by-byte-using-c
  - iterate over the buffer, xorring the bits, then covert to little endian
  - store the contents into the comm_packet structure
*/
#define BUFFER_SIZE 180
struct comm_packet{                               // Offset
   char            Id[4];                         //   0
   char            NodeName[8];                   //   4
   int             NodeNumber;                    //  12
   int             tx_packet_nbr;                 //  16
   int             rx_packet_nbr;                 //  20
   int             track_object_nbr;              //  24
   int             track_object_x_pos;            //  28
   int             track_object_y_pos;            //  32
   int             track_object_z_pos;            //  36
   int             track_object_velocity;         //  40
   int             status_code;                   //  44
   unsigned char   msg_length;                    //  48
   char            status_msg[128];               //  49
};

void print_range_char(int s, int e, char* array){
  for(int i = s; i < e; ++i){
    printf("%c", array[i]);
  }
}
void print_range_integer(int s, int e, char* array){
  for(int i = s; i < e; ++i){
    printf("%i", array[i]);
  }
}

int main(){
  unsigned char key[9] = {0x36,0x13,0x92,0xa5,0x5a,0x27,0xf3,0x00,0x32};
  // // struct comm_packet packet;
  FILE *fp;
  fp = fopen("packet", "rb");
  if(!fp) { printf("Cannot open file, cowardly refusing. It is in the PWD?\n"); exit(1); }
  char buffer[BUFFER_SIZE];
  fread(&buffer, 1, BUFFER_SIZE, fp);
  fclose(fp);
  int index = 0;
  for(int i = 0; i < BUFFER_SIZE; ++i){
    buffer[i] = buffer[i] ^ key[index % 9];
    index++;
  }
  for(int i = 0; i < BUFFER_SIZE; ++i){
    printf("%i\n", buffer[i]);
  }
  printf("\n");
  //
  // print_range_char(0, 3, buffer);
  // printf("\n");
  // print_range_char(4, 11, buffer);
  // printf("\n");
  // print_range_integer(12, 16, buffer);
  // printf("\n");
  // print_range_integer(16, 20, buffer);
  // printf("\n");
  // print_range_integer(20, 24, buffer);
  // printf("\n");
  // print_range_integer(24, 28, buffer);
  // printf("\n");
  // print_range_integer(28, 32, buffer);
  // printf("\n");
  // print_range_integer(32, 36, buffer);
  // printf("\n");
  // print_range_integer(36, 40, buffer);
  // printf("\n");
  // print_range_integer(40, 44, buffer);
  // printf("\n");
  // print_range_integer(44, 48, buffer);
  // printf("\n");
  // print_range_integer(48, 49, buffer);
  // printf("\n");
  // print_range_char(49, 177, buffer);
  // printf("\n");
  return 0;
}
