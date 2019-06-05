#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readingFile(){
  // initialize a variable to be used in reading the file
  string line;
  // assign the file in question to a point on disk
  ifstream myFile ("./readMe.txt");
  // check to see if the file exists
  if (myFile.is_open()){
    // since we do not know the amount of lines in the file, we simply assgin a while loop until it is complete
    while ( getline (myFile, line) ){
      // print each individual line
      cout<< line << endl;
    }
    // once done, close the file as we don't want a memory leak
    myFile.close();
  }
  // oops the file does not exist
  else{
    // use cerr for errors as it is easier to filter stderr
    cerr<< "Unable to open file :(" << endl;
    // give another return value. This is more helpful for Linux bash scripting or possibly using the subprocess python module
    return 1;
  }
  // successful completion of the program yields a zero; no errors encountered
  return 0;
}

int writingToFile(){
  // initialize a varibale to be used in writing to the file
  ofstream myFile ("./readMe.txt");
  if (myFile.is_open()){
    // just some Linux propoganda...that is completely true!
    cout<< "Writing to further the Linux cause!" << endl;
    myFile << "Who needs Windows or Gates when you have Linux?\n";
    myFile << "Long live Tux\n";
    myFile << "Obey Sudo\n";
    myFile << "This message is certified by a GNU\n";
    // make sure you close to prevent a memory leek cause no one likes vegtables that remembers you
    myFile.close();
  }
  else{
    cerr<< "Unable to open file :(" << endl;
    return 1;
  }
  return 0;
}

int reportingFileSize(){
  // think an actual stream of water. Like anything in this world, streams have length. Since we start at the beginning of the stream, we are essentially starting from zero
  // if we denote that we want the beginning and end of the stream, we are only referring to the scope of this single stream or length of the file in our cause
  streampos begin, end;
  // we are telling c++ that the file is intended to be read by a human as it is a compiled (in my case ELF-64 binary) binary. For Mac users it would be Mach-o and for Windows it would be PE-Executable
  ifstream myFile ("/bin/echo", ios::binary);
  // this tell us where we are in space. Since it is the beginning of this file, it is zero
  begin = myFile.tellg();
  // we go until the end of the file
  myFile.seekg(0, ios::end);
  // we then report how far we went
  end = myFile.tellg();
  // close the file for avoiding memory leaks
  myFile.close();
  int sizeOfFile = (end-begin);
  // we would say that the size would be the end minus the beginning for good practice, even if it is subtracting zero
  // this is for offsets in files or points in the file that are certain bytes off from the beginning of the streampos
  cout<< "File size of /bin/echo: " << sizeOfFile << " bytes" << endl;
  cout<< "Begin: " << begin << endl;
  cout<< "End: " << end << endl;
  return 0;
}

int main(){
  // this is so we can determine if the function exited successfully
  // we assign a pointer that is constant (not changing) of the function readingFile so we can capture the return code, not the ouput
  const int& returnCodeReading = readingFile();
  const int& returnCodeWriting = writingToFile();
  // this is some new knowledge. The c++ complier recognizes that debug is a pointer called debug and then can be used to write to /dev/null (almighty black hole of nothingness) or report output error
  FILE* debug;
  // if successful, don't be pedantic, show us the car fax
  if (returnCodeReading == 0 || returnCodeWriting == 0){
    // open up the gates to nothingness
    debug = fopen("/dev/null", "w");
  }
  else{
    // sorry, program ran unsuccessfully so you get all the complaints
    debug = stderr;
  }
  // the nice advantage of fprintf over cout is that we can more efficiently report errors to the user
  fprintf(debug, "Errors, errors everywhere\n");
  // print the return code no matter what
  cout<< "Return code was: " << returnCodeReading << endl;
  // since this part of the function did indeed run successfully, give it a pat on the back and a return code of zero
  reportingFileSize();
  return 0;
}
