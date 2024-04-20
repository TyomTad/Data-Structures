#include <iostream>
#include "new.hpp"

template<typename T>
void print()
{
    T* a = neww<T>();
    *a = 41;
    std::cout << "Single element: " << *a << std::endl;
    deletee(a);

    const size_t size = 5;
    T* arr = neww_array<T>(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = static_cast<T>(i * 10);
    }
    std::cout << "Array elements: ";
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    deletee_array(arr);
}

int main()
{
    print<int>();
    return 0;
}

