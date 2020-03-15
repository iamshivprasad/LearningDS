// HackerrankReverseDoublyLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct DoublyLinkedListNode
{
    int data;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    DoublyLinkedListNode* curr = head;
    DoublyLinkedListNode* prev = curr->prev;
    while (curr != nullptr)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        head = curr;
        curr = curr->prev;
    }

    return head;
}


int main()
{
    DoublyLinkedListNode* first = new DoublyLinkedListNode();
    first->data = 1;

    DoublyLinkedListNode* second = new DoublyLinkedListNode
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
