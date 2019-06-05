#include <iostream>

struct node {
  node* next_;
  int value_;
};

node* find(int value){
  // use an iterator if you are using STL
  node *head_ = nullptr,  *another = nullptr;
  another = head_->next_;
  while(another != nullptr){
    if(value != another->value_){
      another = another->next_;
    }
    else{  return another->next_; }
  }
  return NULL;
}
