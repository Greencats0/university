//
//  intvector.cpp
//
//  Created by William McCarthy on 8/27/18.
//  Tweaked by Jared Dyreson
//  Copyright © 2018 William McCarthy. All rights reserved.
//

#include <iostream>
#include <string.h>
//using namespace std;    // don't do this
using std::cout;
using std::cin;
using std::ostream;
using std::invalid_argument;

class intvector {
public:
      // default c'tor
  intvector() : intvector(10) {}
      // size_t c'tor
  intvector(size_t size) : size_(size), length_(0), data_(new int[size_]) {}
      // copy c'tor
  intvector(const intvector& other) : size_(other.size_), length_(other.length_) {
    data_ = new int[size_];
    memcpy(data_, other.data_, size_ * sizeof(int));
  }
 intvector& operator=(const intvector& other) {
   // wrtie a template for a challange
   size_ = other.size();
   length_ = other.length();
   return *this;
 }
  // destructor
  ~intvector() {    // this is the pointer to the object instance
    // this --->  the current instance of the class
    cout << "deleting " << this << "...\n";
    delete [] data_;
  }

  size_t size() const { return size_; }
  size_t length() const { return length_; }

  int* begin() const { return data_; }          // needed to use for-each loop
  int* end() const { return data_ + length_; }  // note end is ONE BEYOND data_'s area

  void push_back(int val) {
    if (length_ >= size_) { throw new invalid_argument("Buffer overflow"); }
    data_[length_++] = val;
  }

  friend ostream& operator<<(ostream& os, const intvector& iv) {
    if (iv.length_ == 0) { return os << "intvector is empty"; }

    // note: need a begin() and end() function to use this (see above)
    for (auto val : iv) {
      os << val << " ";
    }
    return os;
  }

private:
  size_t size_;
  size_t length_;
  int* data_;
};


int main(int argc, const char * argv[]) {
  intvector iv;

  for (size_t i = 0; i < iv.size(); ++i) { iv.push_back(2 * i); }
  cout << "iv is: " << &iv << iv << "\n";

  intvector iu(iv);
  cout << "after copy c'tor...\niu is: " << &iu << iu << "\n";

  intvector it;
  it = iu;
  cout << "this code will crash until you provide a correct assignment operator\n";
  cout << "after assignment operator...\nit is: " << &it << it << "\n\n";

  return 0;
}
