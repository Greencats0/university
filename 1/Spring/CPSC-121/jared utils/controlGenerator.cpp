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

int main(int argc, char* argv[]){
  // this generates control files for DEB packing
  /*
  Package: io.github.awesomebing1.sbutils
Name: sbutils
Replaces: com.innoying.sbutils
Architecture: iphoneos-arm
Description: iOS utilities - replaces some broken Erica utilities and adds a bunch of new ones. And, this time, it might work. Originally made by innoying.
Maintainer: awesomebing1
Author: awesomebing1
Section: System
Tag: role::hacker
Version: 2.1.1
Installed-Size: 1568
*/
    bool packageConflictsFlag, authorMaintainerFlag;
    string packageName, description, maintainer, author, section, tag, packageConflicts;
    double version;
    int installedSize;
    cout << "Name: ";
    cin >> packageName;
    cout << "Package conflicts[0/1]: ";
    if (packageConflictsFlag){
      cout << "Packages that conflict: ";
      getline(cin, packageConflicts);
    }
    cout << "Description: ";
    getline(cin, description);
    cout << "Author: ";
    cin >> author;
    cout << "Author and Maintainer are the same?[0/1]: ";
    cin >> authorMaintainerFlag;
    if (authorMaintainerFlag){
      maintainer = author;
    }
    else{
      cout << "Maintainer: ";
      cin >> maintainer;
    }
    cout << "Section: ";
    cin >> section;
    cout << "Tag: ";
    getline(cin, tag);
    cout << "Version: ";
    cin >> version;

  return 0;
}
