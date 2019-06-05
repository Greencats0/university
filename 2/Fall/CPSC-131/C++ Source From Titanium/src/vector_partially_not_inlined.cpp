//
//  vector_.cpp
//
//  Created by William McCarthy on 8/27/18.
//  Copyright © 2018 William McCarthy. All rights reserved.
//

#include <iostream>
#include <algorithm>
using std::cout;
using std::ostream;

#define MIN_VECTOR_SIZE   10

template <typename T>
T max_(T a, T b) { return (a > b) ? a : b; }

    // NOTE the extra forward declarations for class vector_ and for operator<<
template <typename T> class vector_;
    // NO EXTRA EMPTY ANGLE BRACKETS HERE (see friend declaration)
template <typename T> ostream& operator<<(ostream& os, const vector_<T>& iv);


template <typename T>
class vector_ {
public:
  vector_() : vector_(MIN_VECTOR_SIZE) {}
  vector_(size_t size) : size_(size), length_(0), data_(new T[size_]) {}
  vector_(const vector_& other) : data_(nullptr) { copy(other); }
  vector_& operator=(const vector_& other) {
    if (this != &other) { copy(other); }
    return *this;
  }
  ~vector_();    // dtor, size() const, and length() const are all implemented outside of the class

  size_t size() const;
  size_t length() const;

  T* begin() const { return data_; }          // needed to use for-each loop
  T* end() const { return data_ + length_; }  // note end is ONE BEYOND data_'s area

  void push_back(T val) {
    if (length_ >= size_) { throw new std::invalid_argument("Buffer overflow"); }
    data_[length_++] = val;
  }
                          //  v------ See the EMPTY ANGLE BRACKETS here (not a typo)
  friend ostream& operator << <>(ostream& os, const vector_<T>& iv);

private:
  void copy(const vector_& other) {
    if (data_ != nullptr) { delete[] data_; }
    size_ = other.size_;
    length_ = other.length_;
    data_ = new T[size_];
    std::copy(other.data_, other.data_ + other.length_, data_);
  }

private:
  size_t size_;
  size_t length_;
  T* data_;
};


template <typename T>
vector_<T>::~vector_() {    // this is the pointer to the object instance
  cout << "deleting " << this << "...\n";
  delete [] data_;
}

template <typename T> size_t vector_<T>::size() const { return size_; }
template <typename T> size_t vector_<T>::length() const { return length_; }

// NO EXTRA ANGLE BRACKETS HERE (in the implementation)
template <typename T>
ostream& operator<<(ostream& os, const vector_<T>& iv) {
  if (iv.length_ == 0) { return os << "vector<T> is empty"; }
  
  // note: need a begin() and end() function to use this (see above)
  for (auto val : iv) {
    os << val << " ";
  }
  return os;
}


int main(int argc, const char * argv[]) {
  vector_<float> iv;

  for (int i = 0; i < iv.size(); ++i) { iv.push_back(0.5 + 2 * i); }
  cout << "iv is: " << &iv << "   " << iv << "\n";

  vector_<float> iu(iv);
  cout << "after copy c'tor...\niu is: " << &iu << "   " << iu << "\n";

  vector_<float> it;
  it = iu;
  cout << "after operator=...\nit is: " << &iu << "   " << iu << "\n";

  cout << "\ncheck for memory errors from the d'tors...\n\n";

  return 0;
}
