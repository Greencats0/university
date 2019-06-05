#include <iostream>

struct n {
  int value_;
  n* next_;
};

// using nodes
int sum(n* p){
  if(p->next_ == nullptr) { return p->value_; }
  return p->value_+sum(p->next_);
}

// using array
int sum(int* p, int n){
  if(n == 1) { return *p; }
  return *p+sum(p+1,n-1);
}

void printListReverse(n* p){
  if(p->next_ == nullptr){ std::cout << p->value_ << std::endl; return; }
  printListReverse(p->next_);
  std::cout << p->value_ << std::endl;
}
void printArrayReverse(int* a, int s){
  // if(a == NULL) { std::cout << *a << std::endl; return; }
  // printArrayReverse(a+1, s-1);
  // std::cout << *a << std::endl;
  if(s <= 1) { return; }
  int t;
  int i=0;
  t = a[i];
  a[i] = a[s-1];
  a[s-1] = t;
  printArrayReverse(&a[1], s-2);
}
void print(int* a, int s, bool order_reverse=false){
  if(s <= 1) { return; }
  if(order_reverse){
    print(a+1, s-1);
    std::cout << *a << std::endl;
  }
  std::cout << *a << std::endl;
  print(a+1, s-1);
}
size_t countNonNegative(int* p, size_t i){
  if(i == 0) { return *p >= 0 ? 1 : 0; }
  return (*p >= 0 ? 1 : 0) + countNonNegative(p+1, i-1);
}

int main(){
  int arr[2] = {1, 2};
  // int s = sum(arr, 2);
  // int a[8] = { -1, 2, 3, -4, 7, -6, -6, 8 };
  // std::cout << countNonNegative(a, 8) << std::endl;
  n node;
  node.value_ = 1;
  n two;
  two.value_ = 2;
  node.next_ = &two;
  // printListReverse(&node);
  // printArrayReverse(arr, 2);
  print(arr, 3, false);
  // std::cout << s << std::endl;
  return 0;
}
