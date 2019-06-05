#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
/*
- steps:
  - read the file into the buffer: https://stackoverflow.com/questions/51224682/read-file-byte-by-byte-using-c
  - iterate over the buffer, xorring the bits, then covert to little endian
  - store the contents into the comm_packet structure
*/

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


int main(){
  unsigned char key[9] = {0x36,0x13,0x92,0xa5,0x5a,0x27,0xf3,0x00,0x32};
  // std::vector<unsigned char> =
  struct comm_packet packet;
  std::fstream stream("packet");
  std::string line, decrypted, unencrypted;
  while(std::getline(stream, line)){ unencrypted+=line; }
  stream.close();
  std::vector<size_t> goop;
  for(auto element : unencrypted) { goop.push_back(int(element)); }
  // for(auto item : goop) { std::cout << char(item ) << std::endl; }
  unsigned long int j = 0;
  for(unsigned long int i = 0; i < 180; ++i){
    // goop[i] = goop[i] ^ key[i % (sizeof(key) / sizeof(char))];
    goop[i] = goop[i]^ key[j];
    if(++j > sizeof(key)){
      j = 0;
    }
    //if(unencrypted[i] == 'C') { std::cout << i << std::endl; }
    //if(i % 9 == 0) { std::cout << std::endl; }
    /*
    if counter is 7, then proceed to change it
    */
  }
  for(auto element : goop) {decrypted+=(char(element)); }
  std::cout << decrypted << std::endl;
  // std::cout << "ID: " << decrypted.substr(0, 4) << std::endl;
  // std::cout << "Node Name: " << decrypted.substr(4, 12) << std::endl;
  return 0;
}
