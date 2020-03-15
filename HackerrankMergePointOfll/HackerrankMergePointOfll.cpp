// HackerrankMergePointOfll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

using namespace std;

struct SinglyLinkedListNode 
{
    int data;
    SinglyLinkedListNode* next;
};

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    int len1 = 0;
    int len2 = 0;

    auto temp1 = head1;
    while (temp1 != nullptr)
    {
        ++len1;
        temp1 = temp1->next;
    }

    temp1 = head2;
    while (temp1 != nullptr)
    {
        ++len2;
        temp1 = temp1->next;
    }

    int diff = len1 - len2;
    int absVal = abs(diff);
    int result = 0;
    if (diff > 0)
    {
        auto p = head1;
        while (absVal > 0)
        {
            --absVal;
            p = p->next;
        }

        auto q = head2;
        while (p != q)
        {
            p = p->next;
            q = q->next;
        }

        result = p->data;
    }
    else {

        auto p = head2;
        while (absVal > 0)
        {
            --absVal;
            p = p->next;
        }

        auto q = head1;
        while (p != q)
        {
            p = p->next;
            q = q->next;
        }

        result = p->data;
    }

    return result;
}

int main()
{

}
