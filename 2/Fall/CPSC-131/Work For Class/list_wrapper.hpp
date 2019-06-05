//
//  slist.h
//  lists
//
//  Created by William McCarthy on 9/18/18.
//  Copyright © 2018 William McCarthy. All rights reserved.
// Wrapper created by Jared Dyreson

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

class slist {
public:
  //------------------------ CONSTRUCTORS ------------------------------------------------
  slist() {}                       // default ctor
  slist(const std::initializer_list<snode>& li) : slist() {   // std::initializer_list<T> ctor
    for (auto el : li) {
      push_back(el.lname_, el.fname_, el.salary_);
    }
  }
  slist& operator=(const std::initializer_list<snode>& li) {  // assignment to std::initializer_list<T> op
    if (li.size() != 0) { erase(); }
    for (auto el : li) {
      push_back(el.lname_, el.fname_, el.salary_);
    }
    return *this;
  }
  slist(const slist& other) : slist() { copy(other); }  // copy ctor
  slist& operator=(const slist& other) {                // assignment operator
    if (this != &other) { copy(other); }
    return *this;
  }
  ~slist() { erase(); }

  //------------------------ ACCESSORS ------------------------------------------------
  snode* front() const { return list.front(); }       // accessors
  snode* back() const { return list.back(); }
  size_t size() const { return list.size(); }
  bool empty() const { return list.size() == 0; }

  //------------------------ MUTATORS ------------------------------------------------
  void erase() {                              // mutators
    while (list.size() > 0) { pop_front(); }  // don't use pop_back() here
  }
  //------------------------ POP METHODS ------------------------------------------------
  void pop_front() {
    check_for_underflow();
    list.pop_front();
  }
  void pop_back() {
    check_for_underflow();
    list.pop_back();
  }

  //------------------------ PUSH METHODS ------------------------------------------------
  void push_front(const std::string& lname, const std::string& fname, float salary) {
    list.prepend(lname, fname, salary);
  }
  void push_back(const std::string& lname, const std::string& fname, float salary) {
    list.append(lname, fname, salary);
  }

  //------------------------ INSERT METHODS ------------------------------------------------
  void insert(const std::string& lnamefind, const std::string& fnamefind, float salaryfind,
              const std::string& lnamenew, const std::string& fnamenew, float salarynew) {
    snode* findnode = new snode(lnamefind, fnamefind, salaryfind);
    insert(findnode, new snode(lnamenew, fnamenew, salarynew));
    delete findnode;
  }
  void insert(snode* snofind, snode* sno) {
    if (size_ == 0 || *snofind == *head_) { prepend(sno); return; }

    snode* p = head_;
    snode* prev = p;
    while (p->next_ != nullptr && *p != *snofind) {  // find a match
      prev = p;
      p = p->next_;
    }
    if (p != nullptr) {
      prev->next_ = sno;
      sno->next_ = p;
      ++size_;
    }
  }
  void insertafter(const std::string& lnamefind, const std::string& fnamefind, float salaryfind,
                   const std::string& lnamenew, const std::string& fnamenew, float salarynew) {
    snode* findnode = new snode(lnamefind, fnamefind, salaryfind);
    insertafter(findnode, new snode(lnamenew, fnamenew, salarynew));
    delete findnode;
  }
  void insertafter(snode* snofind, snode* sno) {
    if (size_ == 0) { insert(snofind, sno);  return; }

    snode* p = head_;
    snode* next = p->next_;
    while (p != nullptr && *p != *snofind) {  // find a match
      p = p->next_;
      next = p->next_;
    }
    if (p != nullptr) {
      p->next_ = sno;
      sno->next_ = next;
      ++size_;
    }
  }

  //------------------------ REMOVE METHODS ------------------------------------------------
  // removes one node
  void remove(const std::string& lname, const std::string& fname, float salary) {
    snode* p = new snode(lname, fname, salary);
    remove(p);
    delete p;
  }
  void remove(snode* sno) {
    check_for_nullptr(sno);

    snode* p = head_;
    snode* prev = head_;
    while (p->next_ != nullptr && *p != *sno) {  // uses snode's operator!=
      prev = p;
      p = p->next_;
    }
    if (p != nullptr) {  // found a matching node
      if (p == head_) { pop_front();
      } else {
        prev->next_ = p->next_;
        delete p;
        --size_;
      }
    }
  }

  void remove_after(const std::string& lname, const std::string& fname,
                    float salary) {
    snode* p = new snode(lname, fname, salary);
    remove_after(p);
    delete p;
  }
  void remove_after(snode* sno) {
    check_for_nullptr(sno);

    snode* p = head_;  // find the matching node (if any)
    while (p != nullptr && *p != *sno) { p = p->next_; }
    if (p == nullptr) { return; }  // no match found

    if (size_ == 1) { pop_front();  return; }  // per Zybooks

    snode* next = p->next_;
    p->next_ = nullptr;      // mark current node as the tail
    p = next;                // move to next to remove the remaining nodes
    while (p != nullptr) {
      next = p->next_;
      delete p;
      p = next;
      --size_;
    }
  }

  //------------------------ PREPEND / APPEND METHODS ------------------------------------------------
  void prepend(const std::string& lname, const std::string& fname, float salary) {
    prepend(new snode(lname, fname, salary, head_));
  }
  void prepend(snode* sno) {
    check_for_nullptr(sno);

    sno->next_ = head_;
    head_ = sno;
    ++size_;
  }

  void append(const std::string& lname, const std::string& fname, float salary) {
    append(new snode(lname, fname, salary));
  }
  void append(snode* sno) {
    check_for_nullptr(sno);
    if (size_ == 0) { prepend(sno);  return; }

    snode* p = head_;
    while (p->next_ != nullptr) {
      p = p->next_;
    }
    p->next_ = sno;
    ++size_;
  }

  //------------------------ RELATIONAL OPERATORS ------------------------------------------------
  friend bool operator==(const slist& a, const slist& b) {    // equality operator
    if (a.size() != b.size()) { return false; }
    snode* pa = a.head_;
    snode* pb = b.head_;
    while (pa != nullptr && pb != nullptr) {
      if (*pa != *pb) { return false; }
      pa = pa->next_;
      pb = pb->next_;
    }
    return true;
  }                                                         // non-equality operator
  friend bool operator!=(const slist& a, const slist& b) { return !operator==(a, b); }

  //------------------------ PRINT OPERATORS (to match Zybooks) --------------------------------
  void print() const { print(std::cout); }    // print to std::cout
  void print(const std::string& filename) {   // print to a file
    std::ofstream ofs;
    ofs.open(filename);
    if (!ofs.is_open()) {
      std::stringstream ss;   // creates a string builder using stream operators
      ss << "Could not open file: " << filename << " for printing to file\n";
      throw new std::invalid_argument(ss.str());   // converts the stream to a string
    }
    print(ofs);
    ofs.close();
  }
  void print(std::ostream& os) const { os << *this; }                   // print to any ostream

  //------------------------ STREAM OPERATORS ------------------------------------------------
  friend std::ostream& operator<<(std::ostream& os, const slist& li) {  // operator<<
    if (li.size_ == 0) { return os << "list is empty"; }
    snode* p = li.head_;
    while (p != nullptr) {
      os << *p << "\n";
      p = p->next_;
    }
    return os;
  }

  //------------------------ HELPER FUNCTIONS ------------------------------------------------
private:    // helper functions
  void copy(const slist& other) {     // copy ctor and assignmennt operator helper
    if (size_ != 0) { erase(); }

    snode* po = other.head_;
    prepend(new snode(po->lname_, po->fname_, po->salary_));

    snode* p = head_;
    snode* next = p;
    po = po->next_;

    while (po != nullptr) {
      next = new snode(po->lname_, po->fname_, po->salary_);
      p->next_ = next;
      p = next;
      po = po->next_;
      ++size_;
    }
  }
  void check_for_nullptr(snode* sno) {
    if (sno == nullptr) { throw new std::invalid_argument("nullptr error"); }
  }
  void check_for_underflow() {
    if (size_ == 0) { throw new std::range_error("underflow"); }
  }

private:
  std::list<T> list;
};


void print(const std::string& msg, const slist& li) {   // local print function
  std::cout << msg << li << "\n";
}

//------------------------ TEST CODE ------------------------------------------------
// void test_list() {      // slist test code
//   std::cout << "\nCalling the copy from std::initializer_list<snode> ctor...\n";
//   slist li = {
//     {"Baggins", "Bilbo", 100},
//     { "Brandybuck", "Merry", 90 },
//     { "Took", "Pippin", 95 },
//     { "Gamgee", "Sam", 80 },
//     { "Oakenshield", "Thorin", 200 }
//   };
//   std::cout << "\nCalling the copy ctor...\n";
//   slist li2(li);
//   slist li3;
//   li3 = li2;
//   std::cout << "\nCalling the assignment operator...\n";
//   std::cout << "li is...\n" << li << "\n";
//   std::cout << "li2 is...\n" << li2 << "\n";
//   std::cout << "li3 is...\n" << li2 << "\n";
//
//   std::cout << "\nli.size is: " << li.size() << "\n";
//   std::cout << "li.empty is: " << li.empty() << "\n";
//
//   std::cout << "\ntesting operator== for slists li and li2... " << (li == li2 ? "EQUAL" : "NOT equal") << "\n";
//   std::cout << "\ntesting operator== for slists li and li3... " << (li == li3 ? "EQUAL" : "NOT equal") << "\n";
//
//   std::cout << "\ntry printing...\n";
//   li.print();
//   std::cout << "\ntry printing to cout...\n";
//   li.print(std::cout);
//   std::string filename = "abc.txt";
//   std::cout << "\ntry printing to file: " << filename << "...\n";
//   li.print(filename);
//
//   std::cout << "try erasing list li2... \n";
//   li2.erase();
//   std::cout << li2 << "\n\n";
//
//   li.remove("Baggins", "Bilbo", 100);
//   print("try removing Bilbo...\n", li);
//
//   li.remove("Took", "Pippin", 95);
//   print("try removing Pippin...\n", li);
//
//   li.remove("Oakenshield", "Thorin", 200);
//   print("try removing Thorin...\n", li);
//
//   li.remove("Gamgee", "Sam", 200);
//   print("try removing Sam...\n", li);
//
//   li.remove("Brandybuck", "Merry", 90);
//   print("try removing Merry...\n", li);
//
// // this will throw an exception, if uncommented...
// //  std::cout << "try popping an empty list... \n";
// //  li2.pop_back();
//
//   std::cout << "\nli3 is still...\n" << li3 << "\n";
//
//   li3.insert("Took", "Pippin", 95, "Elessar", "Aragorn", 500);
//   std::cout << "after insert of Aragorn in front of Pippin, li3 is: \n" << li3 << "\n";
//
//   li3.insertafter("Elessar", "Aragorn", 500, "Evenstar", "Arwen", 510);
//   std::cout << "after insert of Arwen after Aragorn, li3 is: \n" << li3 << "\n";
//
//   li3.pop_back();
//   li3.pop_back();
//   li3.pop_back();
//   li3.pop_back();
//   std::cout << "\nafter four pop_back()s, li3 is: " << li3 << "\n";
//   li3.remove_after("Baggins", "Bilbo", 100);
//   std::cout << "\nafter removing everything after Bilbo... (should remove the head!?)\n";
//   std::cout << li3 << "\n";
// }


#endif /* slist_h */
