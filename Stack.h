//
// Created by Eden on 26/10/2022.
//

#ifndef LOGGING_STACK_STACK_H
#define LOGGING_STACK_STACK_H
#include <iostream>
#include <cassert>
#include <cstring>

template <typename T>
class Stack {

public:
    Stack():m_stackPtr(nullptr),m_top(-1),m_capacity(0){}
    //Stack(const Stack&);

    ~Stack(){delete[] m_stackPtr;
        m_stackPtr= nullptr;
        m_top=0;
        m_capacity=0;
    }
    // setters & getters


    // functions
    void print()const;
    void push(T);
    bool isEmpty()const;
    std::size_t size()const;



private:
    T *m_stackPtr {};
    int  m_top {};
    std::size_t m_capacity {};
};

template<typename T>
bool Stack<T>::isEmpty() const {
    return (m_top==-1);
}

template<typename T>
void Stack<T>::push(T value) {
    if(this->isEmpty()){
        m_stackPtr = new T[1];
        assert(m_stackPtr);
        m_stackPtr[0] = value;
        ++m_top;
        ++m_capacity;
    }
    else{
        auto *tmpPtr = new T[m_capacity*2];
        assert(tmpPtr);
        m_capacity *= 2;
        ++m_top;
        std::memcpy(tmpPtr,m_stackPtr,m_capacity*sizeof(T));
        delete[] m_stackPtr;
        m_stackPtr = nullptr;
        tmpPtr[m_top]=value;
        m_stackPtr = new T[m_capacity];
        assert(m_stackPtr);
        std::memcpy(m_stackPtr,tmpPtr,m_capacity*sizeof(T));
        delete[] tmpPtr;
        tmpPtr= nullptr;
    }
}


template<typename T>
std::size_t Stack<T>::size()const {
    return m_top+1;
}

template<typename T>
void Stack<T>::print() const {
    if (this->isEmpty()){
        std::cout << "empty stack" << std::endl;
    }
    for (int i = 0; i < this->size(); ++i) {
        std::cout << "[" << i << "]" << " -> " << m_stackPtr[i] << std::endl;
    }
}


#endif //LOGGING_STACK_STACK_H
