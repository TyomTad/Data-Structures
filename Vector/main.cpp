#include "Vector.h"
#include <iostream>

int main() {
    // Creating a vector of integers
    g3::vector<int> vec;

    int a = 9;
    // Adding elements to the vector
    vec.push_back(a++);
    vec.push_back(a++);
    vec.push_back(a++);

    // Iterating over the vector and printing its elements
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Accessing elements using operator[]
    std::cout << "First element: " << vec[0] << std::endl;

    // Erasing an element
    vec.erase(vec.cbegin() + 1);

    // Printing the vector after erasing an element
    
     for (int i = 0; i < vec.size(); ++i)
     {
         std::cout << vec[i] << " ";
     }
    std::cout << std::endl;

    return 0;
}
