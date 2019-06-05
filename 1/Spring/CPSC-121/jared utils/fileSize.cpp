#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int calculateFileSize(ifstream &inputFile){
  streampos begin, end;
  begin = inputFile.tellg();
  inputFile.seekg(0, ios::end);
  end = inputFile.tellg();
  inputFile.close();
  int sizeOfFile = (end-begin);
  return sizeOfFile;
}

int main(){
  ifstream myFile;
	myFile.open("/usr/bin/clear");
  int hello;
  hello = calculateFileSize(myFile);
  cout << hello << endl;
  return 0;
}
