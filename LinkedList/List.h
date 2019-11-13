#pragma once

struct Node
{
    int m_Value;
    Node* m_pNext;

    Node() : m_pNext(nullptr), m_Value(-1)
    {

    }
};

class List
{
    public:
        List();

        void Add(int value);

        void InsertInFront(int nValue);

        void ReverseByRecursion();

		void ReverseInGroup(int k);

        void Reverse(Node* pHead);

		Node* Reverse(Node* pHead, int k);

        void Insert(int nValue, unsigned int nPos);

        void Display();

        void Delete(Node* head);

		void DetectAndRemoveLoop();

		static Node* SortedMerge(Node* left, Node* right);

        ~List();

    private:

        Node* m_pFirst;
        Node* m_pLast;


};

