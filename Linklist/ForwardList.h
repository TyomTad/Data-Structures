#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
#include <initializer_list>


template <typename T>
class Linklist{
private:
	class Node{
	public:
		T val;
		Node* next;
		Node(const T& val) : val(val), next(nullptr){}
		Node(T val, Node* tempNext): val(val), next(tempNext){}
	};
	Node* head;
	size_t Size;
public:
	using value_type = T;
    using size_type = size_t;
    using referance = value_type&;
    using const_referance = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
public:
	Linklist();
	Linklist(std::initializer_list<T> initlist);
    Linklist(const Linklist<T>&);
    ~Linklist();
public:
	T& Front();
	void displaylist();
	size_t size();
	T& at(size_t);
	void push_back(const_referance);
	void pop_back();
	void push_front(const_referance);
	void pop_front();
	void insert(size_t, const_referance);
	void erase(size_t);
	bool empty();
	void clear();

};

#include "ForwardList.hpp"

#endif // LINK_LIST.h
