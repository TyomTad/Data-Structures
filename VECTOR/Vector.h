#ifndef __T_VECTOR_HPP__
#define __T_VECTOR_HPP__

#include <initializer_list>
#include <iostream>

template <typename T> class Vector;

template <typename T>
std::istream& operator>>(std::istream& in, Vector<T>& v);

template <typename T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& v);

template <typename T>
class Vector
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;
public:
    Vector();
    Vector(const size_type size);
    Vector(const size_type size, value_type val);
    Vector(const Vector<value_type> & rhv);
    Vector(Vector<value_type>&& rhv);/////
    Vector(std::initializer_list <value_type>);
    ~Vector();

    size_type Size() const;
    size_type max_size() const;
    bool empty() const;
    //void resize(const size_type size, const_reference init = value_type());
    void clear() noexcept;
    size_type capacity() const;
    void reserve(const size_type size);
    void push_back(const_reference element);
    void pop_back();
    void instert(size_type,value_type);
    reference at(size_type ind);
    const_reference at(size_type ind) const;
    const_reference front() const;
    reference front();
    const_reference back() const;
    reference back();
    void resize(size_type s, const_reference val = value_type{});///////

    const Vector<value_type>& operator=(const Vector<value_type>& rhv);
	  const Vector<value_type>& operator=(Vector<value_type>&& rhv);
    reference operator[](const size_type index);
    const_reference operator[](const size_type index) const;
    bool operator==(const Vector<value_type>& rhv) const;
    bool operator!=(const Vector<value_type>& rhv) const;
    bool operator<(const Vector<value_type>& rhv) const;
    bool operator<=(const Vector<value_type>& rhv) const;
    bool operator>(const Vector<value_type>& rhv) const;
    bool operator>=(const Vector<value_type>& rhv) const;

    void insert(size_type pos, const int n, const T& x);
    void insert(size_type pos, const T& x);////
    void insert(size_type pos, std::initializer_list<value_type> init);/////
private:
    value_type m_size;
    value_type m_cap;
    pointer m_ptr;
};

#include "Vector.cpp"
#endif /// __T_VECTOR_HPP__
