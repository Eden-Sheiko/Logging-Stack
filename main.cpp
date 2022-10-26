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
    Stack<int>stack2(stack);
    std::cout << "--------------"  << std::endl;
    std::cout << stack2;
    std::cout << "--------------"  << std::endl;
    std::cout << &stack << " " << &stack2 << std::endl;


    stack2.push(33);
    stack2.push(55);
    std::cout << "--------------"  << std::endl;
    stack = stack2;
    std::cout << stack;
    std::cout << "--------------"  << std::endl;
    std::cout << stack2;
    std::cout << "--------------"  << std::endl;
    std::cout << &stack << " " << &stack2 << std::endl;

    return 0;
}
