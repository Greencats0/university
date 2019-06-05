#include <iostream>
#include <vector>

template <typename T>

struct iterator{
	// given parameters
	iterator(const std::vector<T>& vector, size_t index) : vector_(vector), index_(index) {}
	// default
	iterator(const std::vector<T>& vector) : iterator(vector_, 0){}

	iterator(const iterator& other) = default;
	iterator& operator=(const iterator& other) = default;
	~iterator() = default;
	iterator(iterator&& other) = default;
	iterator& operator=(iterator&& other) = default;
	iterator operator++(){
		++index_;
		return *this;
	} // ++a
	iterator operator++(int){
		// make a copy and then return the copy
		iterator copy_(vector_, index_);
		++copy_;
		return copy_;
	} // a++

	friend iterator operator+(const iterator& a, size_t n){
		return iterator(a.vector_, (a.index_)+n);
	}

	friend iterator operator+(size_t n, const iterator& a){ return operator+(a, n); }

	iterator& operator+=(int n){
		index_ += n;
		return *this;
	}
	void check_range(int n){
		if(index_ + n < 0 || index_ + n >= vector_.size()){
			throw new std::range_error("index out of range");
		}
	}

	friend bool operator<(const iterator& a, const iterator& b) { if(a.vector_ != b.vector_) { throw new std::invalid_argument("vectors not the same"); } return a.index_ < b.index_; }
	// not necessary to write because C++ will auto generate this
	friend bool operator>(const iterator& a, const iterator& b) { return !operator<(a, b); }
	//relational operators
	friend bool operator==(const iterator& a, const iterator& b){ return (a.vector_ == b.vector_) && (a.index_ == b.index_); }
	friend bool operator!=(const iterator& a, const iterator& b) { return !operator==(a, b); }

	T operator[](size_t index){ return *(this + index); }

	T& operator*() { return vector_[index_];}
	const T& operator*() const { return vector_[index_];}

	T& operator->() { return operator*(); }
	T& operator->() const { return operator*(); }

	const std::vector<T>& vector_;

	size_t index_;
};
