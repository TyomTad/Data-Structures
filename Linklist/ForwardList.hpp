#include "ForwardList.h"
#include <iostream>

template<typename T>
Linklist<T>::Linklist()
	:head {nullptr}
	,Size {0}
{}

template<typename T>
Linklist<T>::Linklist(std::initializer_list<T> initlist)
	: head{nullptr}
	, Size{0}
{
	for(const_referance val : initlist)
	{
		push_back(val);
	}
} 

template<typename T>
Linklist<T>::Linklist(const Linklist<T>& rhv)
	: head{nullptr}
	, Size{0}
{
	if(rhv.head == nullptr)
	{
		return;
	}
	Node* current = rhv.head;
	while(current != nullptr)
	{
		push_back(current->val);
		current = current->next;
	}
}

template<typename T>
Linklist<T>::~Linklist()
{
	clear();
} 

template<typename T> 
typename Linklist<T>::referance 
Linklist<T>::Front()
{
	if(empty()){
		throw std::out_of_range("List is empty");
	}
	return head->val;
} 	

template<typename T>
void Linklist<T>::displaylist()
{
	Node* current = this->head;
	while(current){
		std::cout << current->val << "--->";
		current = current->next;
	}
	std::cout << std::endl;
}

template<typename T>
size_t Linklist<T>::size()
{
	size_t size = 0;
	Node* tmp = this->head;
	while(tmp){
		tmp = tmp->next;
		++size;
	} 
	return size;
}

template<typename T>
typename Linklist<T>::referance
 Linklist<T>::at(size_t index)
{
    if (index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->val;	
}

template<typename T>
void Linklist<T>::push_back(const_referance val)
{
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++Size;	
}

template<typename T>
void Linklist<T>::pop_back()
{
	if(this->head == nullptr){
		return;
	}
	if(this->head->next == nullptr){
		delete head;
		head = nullptr;
	}
	else{
		Node* current = this->head;
		while(current->next->next != nullptr){
			current = current->next; 
		}
		delete current->next;
		current->next = nullptr;
	}
	--Size;
}

template<typename T>
void Linklist<T>::push_front(const_referance val)
{
	Node* newnode = new Node(val);
	newnode->next = this->head;
	head = newnode;
	++Size; 
}

template<typename T>
void Linklist<T>::pop_front()
{
	if(head == nullptr){
		return;
	}
	Node* tmp = this->head;
	this->head = this->head->next;
	delete tmp;
	--Size;
}
template<typename T>
void Linklist<T>::insert(size_t index,const_referance val)
{
	if(index >= Size){
		throw 1;
	}
	if(this->head == nullptr)
	{
		return;
	}
	if(index == 0)
	{
		push_front(val);
	}
	else
	{
		Node* current = this->head;
		for(int i = 0;i < index - 1; ++i)
		{
			current = current->next;
		}
			Node* newNode = new Node(val,current->next);
			current->next = newNode;
			++Size;
	}
}

template<typename T>
void Linklist<T>::erase(size_t index){
	if(index >= Size)
	{
		throw 1;
	}
	if(index == 0){
		pop_front();
	}
	else {
		Node* current = this->head;
		for(int i = 0; i < index - 1;++i){
			current = current->next;
		}
	
		Node* del = current->next;
		current->next = del->next;
		delete del;
		--Size;
	}
}

template<typename T>
bool Linklist<T>::empty()
{
	return (Size == 0);
}

template<typename T>
void Linklist<T>::clear()
{
	while(!empty())
	{
		pop_front();
	}
}









































