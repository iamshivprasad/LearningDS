#pragma once


template <typename T>
struct Node
{
    T val;
    Node* next;

    Node<T>(): val(-1), next(nullptr)
    {
    }

private:

    Node<T>(const Node<T>&) = default;
    Node<T>& operator=(const Node<T>&) = default;
};

template <typename T>
class HashTable
{
public:

    HashTable()
    {
        m_chainHeads = new Node<T> * [10]();
    }

    ~HashTable()
    {
        // delete all the pointers
    }

    void insert(T val)
    {
        int hashIdx = val % 10;

        Node<T>* newNode = new Node<T>();
        newNode->val = val;
        newNode->next = nullptr;

        if (m_chainHeads[hashIdx] == nullptr)
        {
            m_chainHeads[hashIdx] = newNode;
        }
        else
        {
            Node<T>* current = m_chainHeads[hashIdx];
            if (current->next == nullptr)
            {
                if (current->val > newNode->val)
                {
                    newNode->next = current;
                    m_chainHeads[hashIdx] = newNode;
                }
                else
                {
                    current->next = newNode;
                }
            }
            else
            {
                Node<T>* prev = m_chainHeads[hashIdx];

                while (current->next != nullptr && current->val < val)
                {
                    prev = current;
                    current = current->next;
                }

                newNode->next = current;
                prev->next = newNode;
            }
        }
    }


private:
    Node<T>** m_chainHeads;
};

