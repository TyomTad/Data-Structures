#include "Stack.h"

int main() {
    g3::stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Size of stack: " << s.size() << std::endl;
    std::cout << "Top of stack: " << s.top() << std::endl;

    s.pop();
    std::cout << "Size of stack after pop: " << s.size() << std::endl;

    g3::stack<int> s2 = {4, 5, 6};

    std::cout << "Is s2 empty? " << (s2.empty() ? "Yes" : "No") << std::endl;

    return 0;
}

