#include <iostream>

struct n {
  int data = 10;
  n* next = nullptr;
  // n* right = nullptr;
};

void print(n* node){
  while(node != nullptr){
    std::cout << node->data << std::endl;
    node = node->next;
  }
}

void test(){
  n* n1 = new n;
  n* n2 = new n;
  n1->next = n2;
  print(n1);
  delete n1;
  delete n2;
  n1 = nullptr;
  n2 = nullptr;
}

int main(){
  test();
  return 0;
}
