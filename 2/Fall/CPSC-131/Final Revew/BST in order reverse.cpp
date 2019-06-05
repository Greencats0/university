#include <iostream>

struct node{
  node* left;
  node* right;
  int data;
  node(int d) : left(nullptr), right(nullptr), data(d){}
};


void printInOrderReverse(node* n){
  if(n == nullptr) { return; }
  printInOrderReverse(n->right);
  std::cout << n->data << std::endl;
  printInOrderReverse(n->left);
}

void test(){
  struct node *root = new node(1);
   root->left = new node(2);
   root->right = new node(3);
   root->left->left = new node(4);
   root->left->right = new node(5);
   printInOrderReverse(root);
}

int main() {
  test();
  return 0;
}
