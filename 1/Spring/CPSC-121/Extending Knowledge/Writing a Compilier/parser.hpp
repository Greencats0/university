// Helper header for Macros and Profit
#include <fstream>
#include <ostream>
#include <string>
#include <iostream>
using namespace std;

class ParsedString{
  private:
    string tab = "\t";
    string space = " ";
  public:
    int numberOfWhiteSpaceCharacters(string s);
    int lengthOfString(string s);
    ParsedString();
    ~ParsedString();

};
