#include <iostream>
#pragma once

template <class T>
struct Node
{
    T m_Value;
    Node<T>* m_pNext;

    Node() : m_pNext(nullptr)
    {

    }
};

template <class T>
class Stack
{
public:
    Stack();
    ~Stack();

    void Push(T c);
    T Pop();
    T Top();

    void Display()
    {
        Node<T>* tmp = m_top;

        while (tmp != nullptr)
        {
            std::cout << tmp->m_Value << "\n";
            tmp = tmp->m_pNext;
        }
    }

    bool IsEmpty()
    {
        return m_top == nullptr ? true : false;
    }

private:

    Node<T>* m_top;

};

