// BTPrintAllPathWithGivenSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

public:
    Node(int n) :data(n), left(nullptr), right(nullptr) {}
};


void ksum(Node* head, int sum, int sumSoFar, vector<int>& s)
{
    if (head == nullptr)
        return;

    sumSoFar += head->data;
    s.push_back(head->data);
    if (sumSoFar == sum)
    {
        cout << endl;
        for (auto a : s)
        {
            cout << a << " " ;
        }
    }
    else
    {
        if (head->left)
            ksum(head->left, sum, sumSoFar, s);

        if (head->right)
            ksum(head->right, sum, sumSoFar, s);
    }

    sumSoFar -= s[s.size() - 1];
    s.pop_back();
}

int main()
{
    //Node* root = new Node(10);
    //root->left = new Node(28);
    //root->left->left = new Node(20);
    //root->left->right = new Node(18);

    //root->right = new Node(13);

    //root->right->left = new Node(14);
    //root->right->right = new Node(15);

    //root->right->left->left = new Node(21);
    //root->right->left->right = new Node(22);
    //root->right->right->left = new Node(23);
    //root->right->right->right = new Node(24);

    Node* root = new Node(2);
    root->left = new Node(20);

    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->left->right = new Node(7);
    root->right->left->left = new Node(6);

    root->right->right = new Node(4);
    root->right->right->left = new Node(1);
    root->right->right->right = new Node(9);

    vector<int> s;
    ksum(root, 10, 0, s);
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
