#include "queue.h"

template<typename T, typename Container>
g3::queue<T,Container>::queue() = default; 

template<typename T, typename Container>
g3::queue<T,Container>::queue(const queue& rhv) 
    : ob{rhv.ob}
{}

template<typename T, typename Container>
g3::queue<T,Container>::queue(queue&& rhv) 
    : ob{std::move(rhv.ob)}
{}

template<typename T, typename Container>
g3::queue<T,Container>::queue(std::initializer_list<value_type> init)
    : ob{init}
{}

template<typename T, typename Container>
template<typename InputIt>
g3::queue<T,Container>::queue(InputIt first , InputIt last) {
    for (auto it = first; it != last; ++it) {
        ob.push(*first);
    }
}

template<typename T, typename Container>
g3::queue<T,Container>::~queue() = default;


template<typename T, typename Container>
const g3::queue<T,Container>&  g3::queue<T,Container>::operator=(const queue& rhv) {
    if (this != &rhv) {
        this->ob = rhv.ob;
    }
    return *this; 
}

template<typename T, typename Container>
const g3::queue<T,Container>& g3::queue<T,Container>::operator=(queue&& rhv) {
    if (this != &rhv) {
        this->ob = std::move(rhv.ob);
    }
    return *this; 
}

template<typename T, typename Container>
typename g3::queue<T,Container>::reference g3::queue<T,Container>::front() {
    return ob.front();
}

template<typename T, typename Container>
typename g3::queue<T,Container>::const_reference g3::queue<T,Container>::front() const {
    return ob.front();
}

template<typename T, typename Container>
typename g3::queue<T,Container>::reference g3::queue<T,Container>::back() {
    return ob.back();
}

template<typename T, typename Container>
typename g3::queue<T,Container>::const_reference g3::queue<T,Container>::back() const{
    return ob.back();
}

template<typename T, typename Container>
bool g3::queue<T,Container>::empty() const {
    return ob.empty();
}

template<typename T, typename Container>
typename g3::queue<T,Container>::size_type g3::queue<T,Container>::size() const {
    return ob.size();
}

template<typename T, typename Container>
void g3::queue<T,Container>::push(const_reference val) {
    return ob.push_front(val);
}

template<typename T, typename Container>
void g3::queue<T,Container>::pop() {
    while(!ob.empty()) {
        ob.pop_back();
    }
}


template<typename T, typename Container>
bool g3::queue<T,Container>::operator==(const queue& other) {
    return ob.size() == other.size();
}

template<typename T, typename Container>
bool g3::queue<T,Container>::operator!=(const queue& other) {
    return ob.size() != other.size();
}

template<typename T, typename Container>
bool g3::queue<T,Container>::operator<(const queue& other) {
    return ob.size() < other.size();
}

template<typename T, typename Container>
bool g3::queue<T,Container>::operator<=(const queue& other) {
    return ob.size() <= other.size();
}

template<typename T, typename Container>
bool g3::queue<T,Container>::operator>(const queue& other) {
    return ob.size() > other.size();
}

template<typename T, typename Container>
bool g3::queue<T,Container>::operator>=(const queue& other) {
    return ob.size() >= other.size();
}
