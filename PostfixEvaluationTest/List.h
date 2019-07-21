#pragma once

template <class T>
struct Node
{
    T m_Value;
    Node* m_pNext;


    Node() : m_pNext(nullptr)
    {

    }
};

template <class T>
class List
{
    public:
        List();

        void Add(T value);

        void InsertInFront(T nValue);

        void ReverseByIteration();

        void Reverse(Node<T>* pHead);

        void Insert(T nValue, unsigned int nPos);

        void Display();

        void Delete(Node<T>* head);

        ~List();

    private:

        Node<T>* m_pFirst;
        Node<T>* m_pLast;

};

