// Checking if given file is a DMG file based off of KOLY Block
// http://newosxbook.com/DMG.html
// Written by Jared Dyreson, inspired by black tea

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
  if(argc < 2){
    cerr << "Usage: magic [file]" << endl;
    exit(1);
  }
  ifstream stream;
  string kolyStr;
  stream.open(argv[1]);
  if(!stream.is_open()){
    cerr << "Cannot open file, cowardly refusing" << endl;
    exit(1);
  }
  stream.seekg(0, ios::end);
  int lengthOfFile = stream.tellg();
  lengthOfFile-=512;
  stream.seekg(lengthOfFile);
  char * buffer = new char[lengthOfFile];
  stream.read(buffer, sizeof(int));
  for(int i = 0; i < 4; i++){
    if(i == 3){
      kolyStr+=buffer[i];
    }
    else{
      kolyStr+=buffer[i];
    }
  }
  for(int i = 0; i < 512; i++){
    cout << buffer[i] << endl;
  }
  stream.close();
  delete [] buffer;
  if(kolyStr == "koly"){
    cout << "Is DMG file" << endl;
  }
  else{
    cerr << "Is not DMG file, this is what the string was \"" << kolyStr << "\"" << endl;
  }
  return 0;
}
