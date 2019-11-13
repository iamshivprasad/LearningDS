// LinkedListMiddleElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Struct  
struct Node
{
    int data;
    struct Node* next;
};

/* Function to get the middle of the linked list*/
//void printMiddle(struct Node* head)
//{
//    struct Node* slow_ptr = head;
//    struct Node* fast_ptr = head;
//
//    if (head != NULL)
//    {
//        while (fast_ptr != NULL && fast_ptr->next != NULL)
//        {
//            fast_ptr = fast_ptr->next->next;
//            slow_ptr = slow_ptr->next;
//        }
//        printf("The middle element is [%d]\n\n", slow_ptr->data);
//    }
//}

void printMiddle(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    if (head != NULL)
    {
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        std::cout << "Middle element: " << slow->data;
    }
}

// Function to add a new node  
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// A utility function to print a given linked list  
void printList(struct Node* ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    // Start with the empty list  
    struct Node* head = NULL;

    // Iterate and add element  
    for (int i = 5; i > 0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }

    return 0;
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
