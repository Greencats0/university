#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int jailbreak(){
  cout << "Jailbreaking iPhone" << endl;
  return 0;
}

int writeToFile(ofstream &write, int counter){
  write.open("./jailbreak_counter");
  write << counter << endl;
  write.close();
  return 0;
}

int readFile(ifstream &stream, string attempts){
  stream.open("./jailbreak_counter");
  getline(stream, attempts);
  int counter = stoi(attempts);
  stream.close();
  return counter;
}

void resetCounter(){
  ifstream stream;
  stream.open("./jailbreak_counter");
  stream.close();
  ofstream write;
  write.open("./jailbreak_counter");
  write << "0" << endl;
  write.close();
  cout << "Jailbreak counter reset successfully" << endl;
}
int main(){
  ifstream stream;
  string attempts;
  int counter = readFile(stream, attempts);
  if (counter < 4){
    cout << "Attempt number: " << counter << endl;
    counter+=1;
    jailbreak();
    ofstream write;
    writeToFile(write, counter);
  }
  else{
    cerr << "Max attempts tried, reboot and try again!" << endl;
    if (remove("./jailbreak_counter") !=0){
      cerr << "Oops, file did not get removed, cowardly refusing" << endl;
    }
    else{
      resetCounter();
    }
  }
  return 0;
}
