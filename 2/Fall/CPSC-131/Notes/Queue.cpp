#include <iostream>
template <typename T>
class Q{
  public:
    Q(size_t s) : size_(s), begin_(0), end_(s--){}
    Q() : Q(0){}

    void checkUnderflow() const{ if(size_ == 0){ throw new std::range_error("underflow"); } }
    void checkOverflow() const { if(size_ >= MAX) { throw new std::range_error("overflow"); }}

    T& front(){ return data_[begin_]; }
    const T& front() const{ return data_[begin_]; }

    T& back() { return data_[end_]; }
    const T& back() const { return data_[end_]; }

    void pop() {
      checkUnderflow();
      data_[begin_] = 0;
      begin_=(begin_+1)%MAX;
    }
    void push(T v){
      checkOverflow();
      end_=(end_+1)%MAX;
      data_[end_+1] = &v;
    }
  private:
    static const size_t MAX = 100;
    T* data_[MAX];
    size_t size_, begin_, end_;
};


int main() {
  Q<int> QQ;
  QQ.push(10);
  std::cout << QQ.front() << std::endl;
}
