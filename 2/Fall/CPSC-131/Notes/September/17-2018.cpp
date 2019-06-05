// this is really confusing me, I need to watch that video
#include <iostream>

// class node_{
//   public:
//     node_();
//     node_(const node_& original);
//     // found here -----> https://stackoverflow.com/questions/22314430/c-linked-list-node-with-class
//     // virtual ~node_();
//     // bool hasNext();
//     // node_* getNext();
//     // void setNext(node_* newNode);
//     // size_t getVal();
//     // void setVal(size_t val);
//
// };

class node_{
  public:
    node_() : node_(0){}
    node_(size_t value, node_* next=nullptr) : value_(value), next_(next) {}
    friend bool operator==(const node_* a, const node_* b){
      return a->value_ == b->value_;
    }
    friend bool operator!=(const node_* a, const node_* b){
      return !operator==(a, b);
    } // go home you're drunk
    friend std::ostream& operator<<(std::ostream& os, const node_& node);
private:
  size_t value_;
  node_* next_;
};

class list_{
  public:
    list_();
    void prepend(size_t value) {
      node_* newNode = new node_(value, head_);
      head_ = newNode;
      ++size_;
    }
    void append(size_t value){
      if(size_ == 0){
        prepend(value);
        return;
      }
      node_* newNode = new node_(value);
      node_* p = head_;
      while(p->next_ != nullptr){
        p=p->next_;
      }
      p->next_ = newNode;
      ++size_;
    }
    void remove(size_t value){
      node_* node = new node_(value);
      node_* p = head_;
      node_* prev = p;
      while((p!=nullptr) && (*p!=*node)){
        prev = p;
        p = p->next_;
      }
      if(p != nullptr){
        prev->next_ = p->next_;
        delete p;
      }
      delete node;

    }
    void erase();
    size_t size() const;
    void print() const{
      node_* p = head_;
      while(p != nullptr){
        std::cout << *p << std::endl;
        p = p->next_;
      }
    }
    void pop_front(){
      if(size_ == 0){
        throw new std::range_error("underflow");
      }
      node_* p = head_;
      head_ = head_->next_;
      delete p;
      --size_;
    }
    bool empty() const;
    friend std::ostream& operator<<(std::ostream& is, const list_& li);
    ~list_(){
      delete head_;
    }
  private:
    node_* head_;
    size_t size_;
};
