// written by Jared Dyreson
// under the GNU GPL V3 License
// cleaned up the code base and was able to tweak the function
// this is a bare bones adaptation of grep, just testing my knowledge
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <boost/algorithm/string/trim.hpp>
using namespace std;
using namespace boost;

void grep(ifstream &input, string pattern){
  // if we did not clear the stream, we would be starting from the middle and that is no bueno
  input.clear();
  input.seekg(0, ios::beg);
  string patternFound;
  int counter = 0;
  if (input.is_open()){
    string line;
    while (getline(input, line)){
      counter++;
      if (line.find(pattern) != string::npos){
        // only accounts for one line of finding
        patternFound = line;
        trim(patternFound);
        cout << counter << ":\t" << patternFound << endl;
        //return patternFound;
      }
    }
  }
  else{
    cerr << "Unable to open file" << endl;
  }
}

// argc is the counter to allow us to see if the correct amount of arguments are present
// argv allows us to parse whatever may come from the user
// int argc, char* argv[]
int main(){
  ifstream streamFile;
  streamFile.open("/home/jared/Desktop/CompSci-CSUF/CPSC-121/Projects/Project Three/airplanes.h");
  cout << "getter functions" << endl;
  grep(streamFile, "get");
  streamFile.seekg(0, ios::beg);
  cout << "Setter functions" << endl;
  grep(streamFile, "set");
  streamFile.seekg(0, ios::beg);
  grep(streamFile, "~");
  streamFile.close();
  return 0;
}
