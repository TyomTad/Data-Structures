#include "Vector.h"

template<typename T,typename Allocator>
g3::vector<T,Allocator>::vector()
  :size_{0}
  , capacity_{0}
  , arr_{nullptr}
{}

template<typename T,typename Allocator>
g3::vector<T,Allocator>::vector(const vector& rhv)
{
  this->size_ = rhv.size_;
  this->capacity_ = rhv.capacity_;
  for(size_type i = 0; i < rhv.size_; ++i){
    this->arr_[i] = rhv.arr_[i];
  }
}

template<typename T,typename Allocator>
g3::vector<T,Allocator>::vector(vector&& rhv)
{
  this = std::move(rhv);  
}

template<typename T,typename Allocator>
g3::vector<T,Allocator>::vector(std::initializer_list<value_type> init)
  :vector()
{
  for(const T &val : init){
    push_back(val);
  }
}

template<typename T,typename Allocator>
g3::vector<T,Allocator>::vector(size_type size,const_reference val)
  :size_{size}
  ,capacity_{size+1}
  ,arr_{nullptr}
{
  if(size > 0){
    for(size_type i = 0; i < size_; ++i){
      arr_[i] = val;
    }
  }
}


template<typename T,typename Allocator>
template<typename InputIt>
g3::vector<T,Allocator>::vector(InputIt first,InputIt last)
{
 for (auto it = first; it != last; ++it){
   push_back(*first);
 } 
}

template<typename T,typename Allocator>
g3::vector<T,Allocator>::~vector() 
{
  clear();
}

template<typename T,typename Allocator>
const g3::vector<T,Allocator>& g3::vector<T,Allocator>::operator=(const vector& rhv)
{
  if(this == &rhv){
    return *this;
  }
  clear();
  size_ = rhv.size_;
  capacity_ = rhv.capacity_;
  arr_ = new value_type[capacity_];
  for(size_type i = 0; i < size_ ; ++i){
    arr_[i] = rhv.arr_[i];
  }
  return *this;
}


template<typename T,typename Allocator>
const g3::vector<T,Allocator>& g3::vector<T,Allocator>::operator=(vector&& rhv)
{
  if(this != &rhv)
  {
    clear();
    capacity_ = rhv.capacity_;
    size_ = rhv.size_;
    arr_ = rhv.arr_;
    rhv.arr_ = nullptr;
    rhv.size_ = 0;
    rhv.size_ = 0;
  }
  return *this;
} 
/////////////////////////////////////////////////////////////
template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::allocator_type
g3::vector<T,Allocator>::get_allocator()
{
  return ob;
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::at(size_type pos)
{
  if(pos < 0 || pos >= size_){
    throw std::out_of_range("Position out of range");
  } 
  return arr_[pos];
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::at(size_type pos) const
{
  if(pos < 0 || pos >= size_){
    throw std::out_of_range("Position out of range");
  } 
  return arr_[pos];
}



template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::operator[](size_type pos)
{
  return arr_[pos];
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::operator[](size_type pos) const
{
  return arr_[pos];
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::front()
{
  return begin();
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::front() const
{
  return begin();
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::back()
{
  return end();
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::back() const
{
  return end();
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::begin()
{
  return iterator(arr_);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::begin() const
{
  return const_iterator(arr_);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::cbegin() const
{
  return const_iterator(arr_);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::end()
{
  return iterator(arr_ + size_);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::end() const
{
  return const_iterator(arr_ + size_);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::cend() const
{
  return const_iterator(arr_ + size_);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::rbegin()
{
  return reverse_iterator(arr_ - 1);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::rbegin() const
{
  return const_reverse_iterator(arr_ - 1);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::crbegin() const
{
  return const_reverse_iterator(arr_ - 1);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::rend()
{
  return reverse_iterator(arr_ - 1 + size_ );
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::rend() const
{
  return const_reverse_iterator(arr_ - 1 + size_);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::crend() const
{
  return const_reverse_iterator(arr_ - 1 + size_);
}

template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::empty() const
{
  return size_ == 0;
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::size_type
g3::vector<T,Allocator>::size() const
{
  return size_;
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::size_type
g3::vector<T,Allocator>::capacity() const
{
  return capacity_;
}

template<typename T,typename Allocator>
void
g3::vector<T,Allocator>::reserve(size_type new_cap)
{
  if(new_cap > capacity_)
  {
 
     value_type* tmp = new value_type[capacity_];
     for(size_type  i = 0; i < size_; ++i)
     {
       tmp[i] = arr_[i];
     }
     delete[] arr_;
     arr_ = tmp;
     tmp =nullptr;
    capacity_ = new_cap;
  }
}

template<typename T,typename Allocator>
void
g3::vector<T,Allocator>::clear() noexcept
{
  size_ = 0;
  capacity_ = 0;
  delete[] arr_;
  arr_ = nullptr;
}

template<typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator
g3::vector<T, Allocator>::insert(const_iterator pos, const_reference val) {

    size_type index = pos.ptr - arr_;
    if (index < 0 || index > size()) {
        throw std::out_of_range("Invalid iterator position");
    }
    if(size_ == capacity_) {  
    this->reserve(capacity_ * 2);
    }
    
    for (size_type i = size_; i > index; --i) {
        arr_[i] = std::move(arr_[i-1]);
    }
    arr_[index] = val;
    ++size_;
    
    return g3::vector<T,Allocator>::iterator(arr_ + index);
}


template<typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator
g3::vector<T, Allocator>::insert(const_iterator pos, size_type count, const_reference val) {
    
    size_type index = pos.ptr + arr_;
    
    if (pos < 0 || pos > size_) {
        throw std::out_of_range("Invalid iterator position");
    }

    size_type old = size_;

    size_ += count;

    if(size_ > capacity_){
      reserve(size_ * 2);
    }
    for (size_type i = old + count - 1; i >= index + count; --i) {
        arr_[i] = std::move(arr_[i - count]);
    }

    for(size_type i = index ; i < index + count; ++i){
      arr_[i] = val;
    }

    return g3::vector<T,Allocator>::iterator(arr_ + index);
}

// Insert overload with initializer list
template<typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator
g3::vector<T, Allocator>::insert(const_iterator pos, std::initializer_list<value_type> init) {
   
   size_type index = pos.ptr - arr_;
   size_type count = init.size();
   size_type old = size_; 

   size_ += count;
    if (size_ > capacity_) {
        reserve(size_ * 2);
    }

    for(size_type i = old + count - 1; i >= index + count; --i)
    {
      arr_[i] = std::move(arr_[i - count]);
    }
  
    for (const auto& val : init) {
        arr_[index++] = val;
    }

    return g3::vector<T,Allocator>::iterator(arr_ + index - count);
}

// Erase overload for single element
template<typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator
g3::vector<T, Allocator>::erase(const_iterator pos) {

   size_type index = pos.ptr - arr_;
   
  for (size_type i = index; i < size_; ++i) {
        arr_[i] = std::move(arr_[i + 1]);
    }

    --size_;
    
    return g3::vector<T,Allocator>::iterator(arr_ + index);
}

template<typename T, typename Allocator>
typename g3::vector<T, Allocator>::iterator
g3::vector<T, Allocator>::erase(const_iterator first, const_iterator last) {

    size_type findex = first.ptr - arr_;
    size_type lindex = last.ptr - arr_;

    size_type shift = lindex - findex + 1;

    for(size_type i = findex ; i < size_ - shift; ++i)
    {
      arr_[i] = std::move(arr_[ i + shift]); 
    }

    size_ -= shift;

    return g3::vector<T,Allocator>::iterator(arr_ + findex);
}


template<typename T,typename Allocator>
void
g3::vector<T,Allocator>::push_back(const_reference val)
{
  if(size_ >= capacity_)
  {
    if(capacity_ == 0){
      reserve(1);
    }else{
    reserve(capacity_ * 2);
    }
    
  }
  arr_[size_++] = val;
}


template<typename T, typename Allocator>
void 
g3::vector<T,Allocator>::pop_back()
{
  if (size_ > 0)
    --size_;
}

template<typename T,typename Allocator>
void 
g3::vector<T,Allocator>::resize(size_type new_size,const_reference val)
{
  if(new_size < size_)
  {
    size_ = new_size;
  }
  else if(size_ < new_size)
  {
    reserve(new_size);
    for(size_type i  = size_; i < new_size; ++i)
    {
      arr_[i] = val;
    }
    size_ = new_size;
  }
}

template<typename T,typename Allocator>
int
g3::vector<T,Allocator>::compare(const vector& other) const
{
  if(size_ < other.size_){
    return -1;
  }else if(size_ > other.size_){
    return 1;
  }
  return 0;
}

template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::operator== (const vector& other) const
{
  return compare(other) == 0;
}

template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::operator!= (const vector& other) const
{
  return compare(other) != 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::operator< (const vector& other) const
{
  return compare(other) < 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::operator<= (const vector& other) const
{
  return compare(other) <= 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::operator> (const vector& other) const
{
  return compare(other) > 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::operator>= (const vector& other) const
{
  return compare(other) >= 0;
}

//////////////////////////////////////////  CONST_ITERATOR  /////////////////////////////////////////
 
template<typename T,typename Allocator>
g3::vector<T,Allocator>::const_iterator::const_iterator(pointer ptr)
  :ptr (ptr)
{}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::const_iterator::operator+(size_type n) const
{
  return const_iterator(ptr + n);
}
 

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::const_iterator::operator-(size_type n) const
{
  return const_iterator(ptr-n);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator&
g3::vector<T,Allocator>::const_iterator::operator++()
{
  ++ptr;
  return *this;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::const_iterator::operator++(int) 
{
  const_iterator tmp = *this;
  ++(*this);
  return tmp;
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator&
g3::vector<T,Allocator>::const_iterator::operator--() 
{
  return const_iterator(--ptr);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_iterator
g3::vector<T,Allocator>::const_iterator::operator--(int)
{
  const_iterator tmp = *this;
  --(*this);
  return tmp;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::const_iterator::operator*() const
{
  return *ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_pointer
g3::vector<T,Allocator>::const_iterator::operator->() const
{
  return ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::const_iterator::operator[](size_type pos) const
{
  return ptr[pos];
}

template<typename T,typename Allocator>
int
g3::vector<T,Allocator>::const_iterator::compare(const const_iterator& new_ptr) const
{
  if(ptr > new_ptr.ptr){
    return -1;
  }else if(ptr < new_ptr.ptr){
    return 1;
  }
  return 0;
}

template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_iterator::operator==(const const_iterator& other) const
{
  return compare(other) == 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_iterator::operator!=(const const_iterator& other) const
{
  return compare(other) == 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_iterator::operator< (const const_iterator& other) const
{
  return compare(other) < 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_iterator::operator <=(const const_iterator& other) const
{
  return compare(other) <= 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_iterator::operator> (const const_iterator& other) const
{
  return compare(other) > 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_iterator::operator>= (const const_iterator& other) const
{
  return compare(other) >= 0;
}

///////////////////////////////////////// CONST_ITERATOR : ITERATOR //////////////////////////////////////

template<typename T,typename Allocator>
g3::vector<T,Allocator>::iterator::iterator(pointer ptr)
{
  const_iterator(this->ptr);
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::iterator::operator+(size_type n) const
{
  return iterator(this->ptr + n);
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::iterator::operator-(size_type n) const
{
  return iterator(this->ptr - n);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator&
g3::vector<T,Allocator>::iterator::operator++()
{
  ++(this->ptr);
  return *this;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::iterator::operator++(int)
{
  iterator tmp = this->ptr;
  ++this->ptr;
  return iterator(tmp);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator&
g3::vector<T,Allocator>::iterator::operator--()
{
  return iterator(--this->ptr);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::iterator
g3::vector<T,Allocator>::iterator::operator--(int)
{
  iterator tmp = this->ptr;
  --this->ptr;
  return iterator(tmp);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::iterator::operator*()
{
  return *(this->ptr);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::pointer
g3::vector<T,Allocator>::iterator::operator->()
{  
  return this->ptr;
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::iterator::operator[](size_type pos) const
{
  return this->ptr[pos];
}

///////////////////////////////////////      CONST_REVERS_ITERATOR    //////////////////////////////////////////
template<typename T,typename Allocator>
g3::vector<T,Allocator>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
  :ptr (ptr)
{}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reverse_iterator
g3::vector<T,Allocator>::const_reverse_iterator::operator+(size_type n) const
{
  return const_revers_iterator(ptr - n);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reverse_iterator
g3::vector<T,Allocator>::const_reverse_iterator::operator-(size_type n) const
{
  return const_revers_iterator(ptr + n);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reverse_iterator&
g3::vector<T,Allocator>::const_reverse_iterator::operator++()
{
  return --ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reverse_iterator
g3::vector<T,Allocator>::const_reverse_iterator::operator++(int)
{
  const_reverse_iterator tmp = ptr;
  --ptr;
  return tmp;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reverse_iterator&
g3::vector<T,Allocator>::const_reverse_iterator::operator--()
{
  return ++ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reverse_iterator
g3::vector<T,Allocator>::const_reverse_iterator::operator--(int)
{
  const_reverse_iterator tmp = ptr;
  ++ptr;
  return tmp;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::const_reverse_iterator::operator*() const
{
  return *ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_pointer
g3::vector<T,Allocator>::const_reverse_iterator::operator->() const
{
  return ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::const_reference
g3::vector<T,Allocator>::const_reverse_iterator::operator[](size_type pos) const
{
  return ptr[pos];
}


template<typename T,typename Allocator>
int
g3::vector<T,Allocator>::const_reverse_iterator::compare (const const_reverse_iterator& new_ptr) const
{
  if(ptr > new_ptr.ptr){
    return -1;
  }else if (ptr < new_ptr.ptr){
    return 1;
  }
  return 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_reverse_iterator::operator==(const const_reverse_iterator& other) const
{
  return compare(other) == 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_reverse_iterator::operator!=(const const_reverse_iterator& other) const
{
  return compare(other) != 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_reverse_iterator::operator>(const const_reverse_iterator& other) const
{
  return compare(other) > 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_reverse_iterator::operator>=(const const_reverse_iterator& other) const
{
  return compare(other) >= 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_reverse_iterator::operator<(const const_reverse_iterator& other) const
{
  return compare(other) < 0;
}


template<typename T,typename Allocator>
bool
g3::vector<T,Allocator>::const_reverse_iterator::operator<=(const const_reverse_iterator& other) const
{
  return compare(other) <= 0;
}

//////////////////////////////////// CONST_REVERSE_ITERATOR : REVERSE_ITERATOR /////////////////////////

template<typename T,typename Allocator>
g3::vector<T,Allocator>::reverse_iterator::reverse_iterator(pointer ptr)
{
  const_reverse_iterator(this->ptr);
}

template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reverse_iterator
g3::vector<T,Allocator>::reverse_iterator::operator+(size_type n) const
{
  return reverse_iterator(this->ptr - n);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reverse_iterator
g3::vector<T,Allocator>::reverse_iterator::operator-(size_type n) const
{
  return reverse_iterator(this->ptr + n);
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reverse_iterator&
g3::vector<T,Allocator>::reverse_iterator::operator++()
{
  return --this->ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reverse_iterator
g3::vector<T,Allocator>::reverse_iterator::operator++(int) 
{
  reverse_iterator tmp = this->ptr;
  --this->ptr;
  return tmp;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reverse_iterator&
g3::vector<T,Allocator>::reverse_iterator::operator--()
{
  return ++this->ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reverse_iterator
g3::vector<T,Allocator>::reverse_iterator::operator--(int)
{
  reverse_iterator tmp = this->ptr;
  ++this->ptr;
  return tmp;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::reverse_iterator::operator*()
{
  return *this->ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::pointer
g3::vector<T,Allocator>::reverse_iterator::operator->()
{
  return this->ptr;
}


template<typename T,typename Allocator>
typename g3::vector<T,Allocator>::reference
g3::vector<T,Allocator>::reverse_iterator::operator[](size_type pos) const
{
  return this->ptr[pos];
}








