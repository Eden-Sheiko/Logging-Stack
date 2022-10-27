#include "Stack.h"
int main() {
    Stack<int>stack;
    Stack<int>stack3;
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
    stack3 = stack2;
    std::cout << stack3;
    std::cout << "--------------"  << std::endl;
    std::cout << stack2;
    std::cout << "--------------"  << std::endl;
    std::cout << &stack3 << " " << &stack2 << std::endl;

    //test for streams

    std::ofstream File;
    File.open("data", std::ios::app | std::ios::binary); // the file to be written
    if (File){
        std::cout << "file exists" << std::endl;
    }
    else {
        std::cout << "file doesn't exist" << std::endl;
    }
    write(File, stack3);
    File.close();
    return 0;
}
