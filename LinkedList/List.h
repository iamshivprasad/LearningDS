#pragma once

struct Node
{
    int m_Value;
    Node* m_pNext;

    Node() : m_pNext(nullptr)
    {

    }
};

class List
{
    public:
        List();

        void Add(int value);

        void InsertInFront(int nValue);

        void ReverseByIteration();

        void Reverse(Node * pHead);

        void Insert(int nValue, unsigned int nPos);

        void Display();

        void Delete(Node* head);

        ~List();

    private:

        Node* m_pFirst;
        Node* m_pLast;

};

