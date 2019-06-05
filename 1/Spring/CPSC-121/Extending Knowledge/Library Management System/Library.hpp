#pragma once

#include <string>
#include <fstream>
using namespace std;

class Book{
  private:
    string authorName, bookName;
    bool isCheckedOut;
  public:
    void setAuthorName(string authorName) { this->authorName = authorName; }
    void setBookName(string bookName){ this->bookName = bookName; }
    void setBookStatus(bool isCheckedOut){ this->isCheckedOut = isCheckedOut; }
    string getAuthorName() { return authorName; }
    string getBookName() { return bookName; }
    bool getBookStatus() { return isCheckedOut; }

};
class Student{
  private:
    string username, password;
  public:
    void setName(string username) { this->username = username; }
    string getUserName() { return username; }
};
