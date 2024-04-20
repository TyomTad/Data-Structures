#include "ForwardList.h"

int main() {
    Linklist<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    std::cout << "Size of list: " << myList.size() << std::endl;

    std::cout << "List contents: ";
    myList.displaylist();
    
    myList.pop_back();

    std::cout << "List contents after popping back: ";
    myList.displaylist();

    return 0;
}

