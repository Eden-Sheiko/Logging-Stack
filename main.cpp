#include "Stack.h"
int main() {
    Stack<int>stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    std::cout << "--------------"  << std::endl;
    std::cout << "size:" << stack.size() << std::endl;
    stack.print();
    std::cout << "--------------"  << std::endl;
    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << stack;

    return 0;
}
