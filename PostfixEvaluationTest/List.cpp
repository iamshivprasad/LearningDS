#include "List.h"
#include <iostream>

template <class T>
List<T>::List() : m_pFirst(nullptr), m_pLast(nullptr)
{
}

template <class T>
void List<T>::Add(T nValue)
{
    Node* newNode = new Node();
    newNode->m_Value = nValue;

    if (m_pFirst != nullptr)
    {
        m_pLast->m_pNext = newNode;
        m_pLast = newNode;
    }
    else
    {
        m_pFirst = newNode;
        m_pLast = newNode;
    }
}

template <class T>
void List<T>::InsertInFront(T nValue)
{
        Node* newNode = new Node();
        newNode->m_Value = nValue;

        if (nullptr == m_pFirst)
        {
            m_pFirst = newNode;
        }
        else
        {
            newNode->m_pNext = m_pFirst;
            m_pFirst = newNode;
        }
}

template <class T>
void List<T>::ReverseByIteration()
{
   Reverse(m_pFirst);
}

template <class T>
void List<T>::Reverse(Node<T>* p)
{
    if (nullptr == p->m_pNext)
    {
        m_pFirst = p;
        return;
    }

    Reverse(p->m_pNext);
    Node* q = p->m_pNext;
    q->m_pNext = p;
    p->m_pNext = nullptr;
}

template <class T>
void List<T>::Insert(T nValue, unsigned int nPos)
{
    Node* newNode = new Node();
    newNode->m_Value = nValue;

    if (0 == nPos)
    {
        newNode->m_pNext = m_pFirst;
        m_pFirst = newNode;

        return;
    }

    Node* tmp = m_pFirst;
    for (int n = 0; n < nPos-2; ++n)
    {
        tmp = tmp->m_pNext;
    }

    newNode->m_pNext = tmp->m_pNext;
    tmp->m_pNext = newNode;
}

template <class T>
void List<T>::Display()
{
    Node* tmp = m_pFirst;

    while (tmp != nullptr)
    {
        std::cout << tmp->m_Value << "\n";
        tmp = tmp->m_pNext;
    }
}

template <class T>
void List<T>::Delete(Node<T>* head)
{
    Node* cur = head;
    Node* next;

    while (cur != nullptr)
    {
        next = cur->m_pNext;

        delete[] cur;

        cur = next;
    }

    head = nullptr;
}

template <class T>
List<T>::~List()
{
    Delete(m_pFirst);
    m_pFirst = nullptr;

}
