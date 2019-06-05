// Same functionality as "strings kernelcache | grep "Darwin""
// Written by Jared Dyreson

#include <string>
#include <iostream>
#include <fstream> // filestream

using namespace std;

int main(){
  ifstream stream;
  string line;
  stream.open("kernelcache_iPhoneSevenPlus1032");
  while(getline(cin, line)){
    if(line.find("Darwin") != string::npos){
      cout << line << endl;
    }
  }
  stream.close();
  return 0;
}
