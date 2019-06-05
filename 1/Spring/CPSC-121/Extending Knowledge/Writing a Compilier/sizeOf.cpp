// writing a better file size tool
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

using namespace std;

size_t totalSize(ifstream &stream){
  if(!stream.is_open()){
    cerr << "File cannot be opened, cowardly refusing" << endl;
    exit(1);
  }
  int begin = stream.tellg();
  stream.seekg(begin, ios::end);
  int endPostion = stream.tellg();
  return (endPostion - begin);
}

void helpMessage(){
  cout << "Usage: sizeOf [OPTION]...[FILE]" << endl;
  cout << "Flags: " << endl;
  cout << " -a\tdisplay all information" << endl;
  cout << " -b\tdisplay size in bytes" << endl;
  cout << " -k\tdisplay size in kilobytes" << endl;
  cout << " -m\tdisplay size in megabytes" << endl;
  cout << " -g\tdisplay size in gigabytes" << endl;
  cout << " -t\tdisplay size in terabytes" << endl;
}

int main(int argc, char** argv){
  if(argc < 3){
    helpMessage();
    exit(1);
  }
  // this is actually a genious idea that totally makes a ton of sense :)
  // found at https://github.com/codyd51/nifz/blob/master/nifz.c
  enum magnitude{
    kilobyte = 1,
    megabyte,
    gigabyte,
    terabyte
  };
  ifstream stream;
  stream.open(argv[2]);
  float fileSize = totalSize(stream);
  int c;
  while((c = getopt(argc, argv, "a:b:k:m:g:t:h:")) != -1){
    switch(c){
      case 'a':
      cout << fileSize << endl;
      for (int i = kilobyte; i <= terabyte; i++){
        for(int j = kilobyte; j<= i; j++){
          fileSize/=1024.0;
        }
        cout << fileSize << endl;
      }
      break;
      case 'b':
        cout << fileSize << endl;
        break;
      case 'k':
        cout << (fileSize/=(pow(1024.0, kilobyte))) << endl;
        break;
      case 'm':
        cout << (fileSize/=(pow(1024.0, megabyte))) << endl;
        break;
      case 'g':
        cout << (fileSize/=(pow(1024.0, gigabyte))) << endl;
        break;
      case 't':
        cout << (fileSize/=(pow(1024.0, terabyte))) << endl;
        break;
      case 'h':
        helpMessage();
        break;
      default:
        helpMessage();
    }
  }
  stream.close();
  return 0;
}
