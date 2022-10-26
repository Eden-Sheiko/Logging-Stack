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
      friend inline std::ostream& operator<<(std::ostream& output,const Stack &ref){
        output << " size: " << ref.size() << "\n";
        output << " is empty?: " << ref.isEmpty() << "\n";
          for (int i = 0; i < ref.size(); ++i) {
              std::cout << "[" << i << "]" << " -> " << ref.m_stackPtr[i] << std::endl;
          }
        return output;
    }
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
    T pop();
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
        auto *tmpPtr = new T[++m_capacity];
        assert(tmpPtr);
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

template<typename T>
T Stack<T>::pop() {
    if(this->isEmpty()){
        std::exit(EXIT_FAILURE);
    }
    T tmp = 0;
    for (auto i = 0; i < this->size()-1; ++i) {
        tmp = m_stackPtr[i];
    }
    auto *tmpPtr = new T[--m_capacity];
    assert(tmpPtr);
    --m_top;
    std::memcpy(tmpPtr,m_stackPtr,m_capacity*sizeof(T));
    delete[] m_stackPtr;
    m_stackPtr = nullptr;
    m_stackPtr = new T[m_capacity];
    assert(m_stackPtr);
    std::memcpy(m_stackPtr,tmpPtr,m_capacity*sizeof(T));
    delete[] tmpPtr;
    tmpPtr= nullptr;
    return tmp;
}


#endif //LOGGING_STACK_STACK_H
