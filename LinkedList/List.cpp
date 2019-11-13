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

void List::ReverseByRecursion()
{
   Reverse(m_pFirst);
}

void List::ReverseInGroup(int k)
{
	m_pFirst = Reverse(m_pFirst, k);

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

Node* List::Reverse(Node* pHead, int k)
{
	if (nullptr == pHead || nullptr == pHead->m_pNext)
	{
		return pHead;
	}

	int i = 1;
	Node* curr = pHead, *next, *prev = nullptr;

	while (i <= k && curr != nullptr)
	{
		next = curr->m_pNext;
		curr->m_pNext = prev;
		
		prev = curr;
		curr = next;

		++i;
	}
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

void List::DetectAndRemoveLoop()
{
	Node* pSlow = m_pFirst;
	Node* pFast = m_pFirst;

	bool bIsLoop = false;
	while (pSlow && pFast && pFast->m_pNext)
	{
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext->m_pNext;

		if (pSlow == pFast)
		{
			bIsLoop = true;
			break;
		}
	}

	// To find the start of the loop
	// Set pSlow to head and move pFast one at a time
	if (bIsLoop) 
	{
		pSlow = m_pFirst;
		while (pSlow->m_pNext != pFast->m_pNext)
		{
			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
		}

		pFast->m_pNext = nullptr;

	}

}

Node* List::SortedMerge(Node* left, Node* right)
{
	if (left == nullptr || right == nullptr)
		return nullptr;

	Node* first = left;
	Node* second = right;

	Node* newHead = nullptr;
	Node* result = nullptr;

	while (true)
	{
		if (first == nullptr)
		{
			result->m_pNext = second;
			break;
		}

		if (second == nullptr)
		{
			result->m_pNext = first;
			break;
		}
		


		if (first->m_Value <= second->m_Value)
		{
			if (newHead == nullptr)
			{
				result = newHead = first;				
			}
			else
			{
				result->m_pNext = first;
				result = first;
			}
			first = first->m_pNext;

		}
		else
		{
			if (newHead == nullptr)
			{
				result = newHead = second;
			}
			else
			{
				result->m_pNext = second;
				result = second;
			}
			second = second->m_pNext;
		}
	}

	return newHead;
}

List::~List()
{
    Delete(m_pFirst);
    m_pFirst = nullptr;

}
