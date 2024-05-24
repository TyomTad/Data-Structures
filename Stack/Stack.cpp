#include "Stack.h"

template<typename T, typename Container>
g3::stack<T, Container>::stack() = default;

template<typename T, typename Container>
g3::stack<T, Container>::stack(const stack& rhv) 
    : ob(rhv.ob) {}

template<typename T, typename Container>
g3::stack<T, Container>::stack(stack&& rhv) noexcept 
    : ob(std::move(rhv.ob)) {}

template<typename T, typename Container>
g3::stack<T, Container>::stack(std::initializer_list<T> init) 
    : ob(init)  
{}

template<typename T, typename Container>
template<typename InputIt>
g3::stack<T, Container>::stack(InputIt first, InputIt last)
    : stack()
{
    for(auto it = first; it != last; ++it) {
        ob.push(*it);
    }
}

template<typename T, typename Container>
g3::stack<T, Container>::~stack() noexcept = default;

template<typename T, typename Container>
const g3::stack<T, Container>& g3::stack<T, Container>::operator=(const stack& rhv) {
    if (this != &rhv) {
        this->ob = rhv.ob;
    }
    return *this;
}

template<typename T, typename Container>
const g3::stack<T, Container>& g3::stack<T, Container>::operator=(stack&& rhv) {
    if (this != &rhv) {
        this->ob = std::move(rhv.ob);
    }
    return *this;
}

template<typename T, typename Container>
typename g3::stack<T, Container>::reference g3::stack<T, Container>::top() {
    return ob.back();
}

template<typename T, typename Container> 
typename g3::stack<T, Container>::const_reference g3::stack<T, Container>::top() const {
    return ob.back();
}

template<typename T, typename Container>
bool g3::stack<T, Container>::empty() const {
    return ob.empty();
}

template<typename T, typename Container>
typename g3::stack<T, Container>::size_type g3::stack<T, Container>::size() const {
    return ob.size();
}

template<typename T, typename Container>
void g3::stack<T, Container>::push(const_reference val) {
    ob.push_back(val);
}

template<typename T, typename Container>
void g3::stack<T, Container>::pop() {
    if (!ob.empty()) {
        ob.pop_back();
    }
}

template<typename T, typename Container>
bool g3::stack<T, Container>::operator==(const stack& other) {
    return ob.size() == other.size();
}

template<typename T, typename Container>
bool g3::stack<T, Container>::operator!=(const stack& other) {
    return ob.size() != other.size();
}

template<typename T, typename Container>
bool g3::stack<T, Container>::operator<(const stack& other) {
    return ob.size() < other.size();
}

template<typename T, typename Container>
bool g3::stack<T, Container>::operator<=(const stack& other) {
    return ob.size() <= other.size();
}

template<typename T, typename Container>
bool g3::stack<T, Container>::operator>(const stack& other)  {
    return ob.size() > other.size();
}

template<typename T, typename Container>
bool g3::stack<T, Container>::operator>=(const stack& other) {
    return ob.size() >= other.size();
}

