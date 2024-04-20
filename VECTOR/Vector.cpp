#ifndef __T_VECTOR_CPP__
#define __T_VECTOR_CPP__



#include "Vector.h"
#include <climits>

///////////////////////////constructors
template<typename T>
Vector<T>::Vector()
  :m_size {0}
  ,m_cap {0}
  ,m_ptr{nullptr}
{}


template<typename T>
Vector<T>::Vector(const size_type size)
  :m_size {size}
  ,m_cap {size}
  ,m_ptr {new value_type[m_size]}
{}

template<typename T>
Vector<T>::Vector(const size_type size,value_type val)
      :Vector(size)
{
  for(size_type i = 0; i < m_size; ++i)
  {
    this->m_ptr[i] = val;
  }
}

template<typename T>
Vector<T>::Vector(const Vector<value_type>& rhv)
{
  this->m_size = rhv.m_size;
  this->m_cap = rhv.m_cap;
  for(size_type i = 0; i < rhv.m_size; ++i)
  {
    this->m_ptr[i] = rhv.m_ptr[i];
  }
}

template<typename T>
Vector<T>::Vector(std::initializer_list<value_type> init)
    : Vector(0)
{
    for (const T &val : init)
    {
        push_back(val);
    }

}

template<typename T>
Vector<T>::~Vector()
{
  clear();
}

//////////////////////// functions

template<typename T>
typename Vector<T>::size_type
Vector<T>::Size() const
{
  return this->m_size;
}

template<typename T>
typename Vector<T>::size_type
Vector<T>::max_size() const
{
  return LLONG_MAX / sizeof(value_type);
}

template<typename T>
bool Vector<T>::empty() const
{
  if(this->m_ptr == nullptr)
  {
    return true;
  } else {
    return false;
  }
}

template<typename T>
void Vector<T>::clear() noexcept
{
  this->m_size = 0;
  this->m_cap = 0;
  delete[] this->m_ptr;
  this->m_ptr = nullptr;
}

template<typename T>
typename Vector<T>::size_type
Vector<T>::capacity() const
{
  return this->m_cap;
}

template<typename T>
void Vector<T>::reserve(const size_type size)
{
  if (size > this->m_cap){
    m_cap = size;
    value_type* tmp = new value_type[m_cap];
    for(size_type i = 0 ; i < m_size; ++i)
    {
      tmp[i] = m_ptr[i];
    }
    delete[] m_ptr;
    m_ptr = tmp;
  }
}

template<typename T>
void Vector<T>::push_back(const_reference element)
{
  if(m_size >= m_cap)
  {
    reserve(m_cap == 0 ? 1 : (m_cap * 2));
  }
    
  m_ptr[m_size++] = element;
}

template<typename T>
void Vector<T>::pop_back()
{
  delete[] m_ptr[m_size];
  --m_size;
}

template<typename T>
void Vector<T>::instert(size_type index,value_type val)
{
  if(index < 0 || index > m_size)
  {
    throw std::out_of_range("Invalid index");
  }
  if(m_size > m_cap)
  {
    reserve(m_cap == 0 ? 1 : m_cap * 2);
  }
  for(size_type i = m_size; i > index; --i)
  {
    m_ptr[i] = m_ptr[i-1];
  }
  m_ptr[index] = val; 
  ++m_size;
}

template<typename T>
typename Vector<T>::reference
Vector<T>::at(size_type ind)
{
  if(ind < 0 || ind >= m_size)
  {
    throw std::out_of_range("Index out of range");
  }
  return m_ptr[ind];
}

template<typename T>
typename Vector<T>::const_reference
Vector<T>::at(size_type ind) const
{
  if(ind < 0 || ind >= m_size)
  {
    throw std::out_of_range("Index out of range");
  }
  return m_ptr[ind];
}

template<typename T>
typename Vector<T>::const_reference
Vector<T>::front() const
{
  if(m_size == 0)
  {
    throw std::out_of_range("Index out of range");
  }
  return m_ptr[m_size-1];
}

template<typename T>
typename Vector<T>::reference
Vector<T>::front()
{
  if(m_size == 0)
  {
    throw std::out_of_range("Index out of range");
  }
  return m_ptr[0];
}

template<typename T>
typename Vector<T>::reference
Vector<T>::back()
{
  if(m_size == 0)
  {
    throw std::out_of_range("Index out of range");
  }
  return m_ptr[m_size - 1];  
}

template<typename T>
typename Vector<T>::const_reference
Vector<T>::back() const
{
  if(m_size == 0)
  {
    throw std::out_of_range("Index out of range");
  }
  return m_ptr[0];
}

template<typename T>
void Vector<T>::resize(size_type s,const_reference val)
{
  if(s < m_size)
  {
    m_size = s;
  }
  else if(s > m_size)
  {
    reserve(s);
    for(size_type i = m_size ; i < s; ++i)
    {
      m_ptr[i] = val;
    }
    m_size = s;
  }
}

template<typename T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& rhv)
{
  if(this == &rhv)
  {
    return *this;
  }
  clear();
  m_size = rhv.m_size;
  m_cap = rhv.m_cap;
  m_ptr = new value_type[m_cap];
  for(size_type i = 0; i < m_size; ++i)
  {
    m_ptr[i] = rhv.m_ptr[i];
  }
  return *this;
}

template<typename T>
const Vector<T>& Vector<T>::operator=(Vector<value_type>&& rhv)
{
  if(this != &rhv)
  {
     clear();
     m_cap = rhv.m_cap;
     m_size = rhv.m_size;
     m_ptr = rhv.m_ptr;
     rhv.m_ptr = nullptr;
     rhv.m_cap = 0;
     rhv.m_size = 0; 
  }
  return *this;
}

template<typename T>
typename Vector<T>::reference
Vector<T>::operator[](const size_type index)
{
  return m_ptr[index];
}

template<typename T>
typename Vector<T>::const_reference
Vector<T>::operator[](const size_type index) const
{
  return m_ptr[index];
}

template<typename T>
bool Vector<T>::operator== (const Vector<value_type>& rhv) const
{
  if(this->m_size != rhv.m_size)
  {
    return false;
  }
  
  for(size_type i = 0; i < m_size; ++i)
  {
    if(this->m_ptr[i] != rhv.m_ptr[i])
    {
        return false;
    }
  }
  return true;
}


template<typename T>
bool Vector<T>::operator!= (const Vector<value_type>& rhv) const
{
  return !operator==(rhv);
} 

template<typename T>
bool Vector<T>::operator< (const Vector<value_type>& rhv) const
{
  size_type tmp = (this->m_size < rhv.m_size ? this->m_size : rhv.m_size);
    for(size_type i = 0 ; i < tmp; ++i)
    {
      if(this->m_ptr[i] >= rhv.m_ptr[i])
      {
        return false;
      }
    }
    return true;
}

template <typename T>
bool Vector<T>::operator<= (const Vector<value_type> &rhv) const
 {    
    if( operator==(rhv))
    {
      return true;
    }
    size_type tmp = (this->m_size < rhv.m_size ? this->m_size : rhv.m_size);
    for(size_type i = 0 ; i < tmp; ++i)
    {
      if(this->m_ptr[i] > rhv.m_ptr[i])
      {
        return false;
      }
    }
    return true;
}


template<typename T>
bool Vector<T>::operator> (const Vector<value_type>& rhv) const
{
  size_type tmp = (this->m_size > rhv.m_size ? this->m_size : rhv.m_size);
    for(size_type i = 0 ; i < tmp; ++i)
    {
      if(this->m_ptr[i] <= rhv.m_ptr[i])
      {
        return false;
      }
    }
    return true;
}




template<typename T>
bool Vector<T>::operator>= (const Vector<value_type>& rhv) const
{
  if( operator==(rhv))
  {
    return true;
  }
  size_type tmp = (this->m_size > rhv.m_size ? this->m_size : rhv.m_size);
    for(size_type i = 0 ; i < tmp; ++i)
    {
      if(this->m_ptr[i] <= rhv.m_ptr[i])
      {
        return false;
      }
    }
    return true;
}

template<typename T>
void Vector<T>::insert(size_type pos,const int n, const T& x)
{
  for(size_type i = 0; i < n; ++i)
  {
      insert(pos,x);
  }
}

template<typename T>
void Vector<T>::insert(size_type pos, const T& x)
{
    ++m_size;
    for(size_type i = m_size-1; i > (m_size - pos); --i)
    {
      m_ptr[i] = m_ptr[i-1];
    }
    m_ptr[pos] = x;
}

template<typename T>
void Vector<T>::insert(size_type pos,std::initializer_list<value_type> init)
{
  size_type tmp = init.size();
  resize(m_size + tmp);
  for(size_type i = m_size-1 ; i >= pos + tmp; --i)
  {
    m_ptr[i] = m_ptr[i - tmp];
  }
  size_type index = pos;
  for(const T& val : init) {
     m_ptr[index++] = val;
  }
}


#endif //
