#include "pch.h"
#include "List.h"
#include <iostream>


List::List() : m_pFirst(nullptr)
{
}

void List::Add(int nValue)
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

void List::InsertInFront(int nValue)
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

void List::ReverseByIteration()
{
   Reverse(m_pFirst);
}

void List::Reverse(Node* p)
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

void List::Insert(int nValue, unsigned int nPos)
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

void List::Display()
{
    Node* tmp = m_pFirst;

    while (tmp != nullptr)
    {
        std::cout << tmp->m_Value << "\n";
        tmp = tmp->m_pNext;
    }
}

void List::Delete(Node* head)
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

List::~List()
{
    Delete(m_pFirst);
    m_pFirst = nullptr;

}
