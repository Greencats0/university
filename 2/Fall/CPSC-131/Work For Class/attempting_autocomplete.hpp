#ifndef slist_h
#define slist_h


#include <fstream>
#include <sstream>
#include <list>
#include <iostream>

struct snode {
  snode() : snode("", "", 0) {}                // default ctor
  snode(const std::string& lname, const std::string& fname, float salary,
        snode* next=nullptr)
  : lname_(lname), fname_(fname), salary_(salary), next_(next) {}  // string, string, float snode* ctor

  friend bool operator==(const snode& a, const snode& b) {       // equality operator
    return a.lname_ == b.lname_ &&
    a.fname_ == b.fname_ &&
    a.salary_ == b.salary_;
  }
  friend bool operator!=(const snode& a, const snode& b) {      // non-equality operator
    return !operator==(a, b);
  }
  friend bool operator<(const snode& a, const snode& b) {       // less than operator
    return
    (a.lname_ < b.lname_) ||
    (a.lname_ == b.lname_ && a.fname_ < b.fname_) ||
    (a.lname_ == b.lname_ && a.fname_ == b.fname_ && a.salary_ < b.salary_);
  }
  friend std::istream& operator>>(std::istream& is, snode& sno) {   // istream (extraction) operator
    // if reading from a file, list must reset its next pointers
    // we cannot count on memory location when the list is saved
    // to be the same as when we read it back in from a file
    sno.next_ = nullptr;
    return is >> sno.lname_ >> sno.fname_ >> sno.salary_;
  }
  friend std::ostream& operator<<(std::ostream& os, const snode& sno) {  // ostream (insertion) operator
    return os << sno.lname_ << ", " << sno.fname_ << ", $" << sno.salary_
    << " (" << &sno << ") ---> " << sno.next_;
  }
  std::string lname_;
  std::string fname_;
  float salary_;
  snode* next_;
};

template <typename T>
class slist{
  private:
    std::string str;
    std::list<T> list;
  public:
    slist(){} //default constructor

    // create a list easier. This was introduced into C++11
    slist(const std::initializer_list<snode>& li) : slist() {
      for(auto element : li){
        // push_back --> add data to the end of the list
        std::cout << "I need to define push_back" << std::endl;
      }
    }
    // void pop_front() {
    //   linkedlist.pop_front();
    // }
    void help(){
      std::cout << "Whut" << std::endl;
    }

};

#endif
