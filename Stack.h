//
// Created by Eden on 26/10/2022.
//

#ifndef LOGGING_STACK_STACK_H
#define LOGGING_STACK_STACK_H

template <typename T>
class Stack {

public:
    Stack():m_stackPtr(nullptr){}
    //Stack(const Stack&);

    ~Stack(){delete[] m_stackPtr;}
    // setters & getters


    // functions

    bool isEmpty()const;


private:
    T *m_stackPtr;
};

template<typename T>
bool Stack<T>::isEmpty() const {
    return (m_stackPtr == nullptr);
}


#endif //LOGGING_STACK_STACK_H
