#include "Stack.h"
int main() {
    Stack<int>stack;
    std::cout << "empty:" << stack.isEmpty() << std::endl;
    //std::cout << "full:" << stack.isFull() << std::endl;
    std::cout << "size:" << stack.size() << std::endl;
    stack.push(1);
    std::cout << "--------------"  << std::endl;
    std::cout << "empty:" << stack.isEmpty() << std::endl;
    std::cout << "size:" << stack.size() << std::endl;
    stack.push(2);
    std::cout << "--------------"  << std::endl;
    std::cout << "size:" << stack.size() << std::endl;
    stack.print();

    return 0;
}
