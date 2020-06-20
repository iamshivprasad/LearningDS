// BTSymmetricTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int n): data(n), left(nullptr), right(nullptr){}
};

bool IsSymmetric(Node* l, Node* r)
{
    if (l == nullptr && r == nullptr)
        return true;

    if (l == nullptr || r == nullptr)
    {
        return false;
    }

    if (l->data == r->data &&
        IsSymmetric(l->left, r->right) &&
        IsSymmetric(l->right, r->left))
        return true;

    return false;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << IsSymmetric(root, root);
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
