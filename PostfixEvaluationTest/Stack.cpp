#include "Stack.h"
#include <iostream>
#include <exception>

template <class T>
Stack<T>::Stack() : m_top(nullptr)
{
}


template <class T>
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::Push(T c)
{
    Node<T>* newNode = new Node<T>();
    newNode->m_Value = c;

    if (nullptr == m_top)
    {
        m_top = newNode;
    }
    else
    {
        newNode->m_pNext = m_top;
        m_top = newNode;
    }
}

template <class T>
T Stack<T>::Top()
{
    if (m_top == nullptr)
    {
        throw "Empty stack";
    }
    return m_top->m_Value;
}

template <class T>
T Stack<T>::Pop()
{
    if (m_top == nullptr)
    {
        throw std::exception("Empty stack!!!");
    }

    T val = m_top->m_Value;
    Node<T>* tmp = m_top->m_pNext;
    delete m_top;
    m_top = nullptr;

    m_top = tmp;

    return val;
}

//template <class T>
//void Stack<T>::Display()
//{
//    Node<T>* tmp = m_top;
//
//    while (tmp != nullptr)
//    {
//        std::cout << tmp->m_Value << "\n";
//        tmp = tmp->m_pNext;
//    }
//}