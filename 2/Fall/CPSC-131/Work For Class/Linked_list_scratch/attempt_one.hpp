// requirements
/*
head, tail
front, back
insertion; front, end, position
*/

#include <iostream>
template <typename T>
class node{
  node(T data) : data_(data), next_(nullptr), previous_(nullptr){}
  T data_;
  node *next_, *previous_;
};

template <typename T>
class list{
  public:
    // creating and destroying objects
    list();
    list(const list& li);
    list operator=(const list& li);
    ~list();

    // accessing data
    node<T>* front() const;
    node<T>* back() const;
    T data() const;

    // functionality
    void copy(const list& li);

  private:
    node<T> *head_, *tail_;
    size_t size_;

  private:
};


template <typename T>
list<T>::list(){}

template <typename T>
list<T>::list(const list& li){

}

template <typename T>
T list<T>::data() const{

}

template <typename T>
node<T>* list<T>::back() const{ return tail_; }

template <typename T>
node<T>* list<T>::front() const { return head_; }

template <typename T>
void list<T>::copy(const list<T>& li){
  
}
