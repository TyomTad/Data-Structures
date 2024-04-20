#include <iostream>
#include "Vector.h" // Include the implementation file

int main() {
    // Create a Vector of integers
    Vector<int> vec;
    std::cout  << "chlp" << std::endl;

    // Push some elements into the vector
    vec.push_back(10);
    std::cout << "1" << std::endl;
    vec.push_back(20);
    std::cout << "2" << std::endl;
    vec.push_back(30);

    // Print the size of the vector
    std::cout << "Vector size: " << vec.Size() << std::endl;

    // Print the elements of the vector
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.Size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Modify an element of the vector
    vec[1] = 25;

    // Print the modified vector
    std::cout << "Modified vector elements: ";
    for (size_t i = 0; i < vec.Size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Insert an element at a specific position
    vec.insert(1, 15);

    // Print the vector after insertion
    std::cout << "Vector elements after insertion: ";
    for (size_t i = 0; i < vec.Size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

