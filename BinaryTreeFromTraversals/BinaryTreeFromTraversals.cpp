// BinaryTreeFromTraversals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

map<int, int> table;

struct Node
{
    char data;
    Node* left;
    Node* right;

public:
    Node(int n) : data(n), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<char> arr[], int start, int end)
{
    static int preIndex = 0;
    
    if (start > end)
    {
        return NULL;
    }

    Node* newNode = new Node(arr[0][preIndex++]);
    if (start == end)
    {
        return newNode;
    }

    newNode->left = buildTree(arr, start, table[newNode->data] - 1);
    newNode->right = buildTree(arr, table[newNode->data] + 1, end);

    return newNode;
}

void preOrder(Node* head)
{
    if (head == nullptr)
        return;

    cout << head->data << endl;
    
    preOrder(head->left);
    preOrder(head->right);
}

// Need only one traversal
Node* buildBinarySearchTree(vector<int> arr)
{
    Node* root = new Node(arr[0]);
    Node* p = root;
    stack<Node*> s;

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] < p->data)
        {
            Node* t = new Node(arr[i]);
            p->left = t;
            s.push(p);
            p = t;
        }
        else if(arr[i] > p->data)
        {
            Node* top = s.top();
            Node* t = new Node(arr[i]);

            if (top->data > arr[i])
            {
                p->right = t;
                p = t;
            }
            else
            {
                s.pop();
                top->right = t;
                p = top;
            }
        }
    }
}

int main()
{
    std::cout << "Enter the size of array:" << endl;

    int size = 0;
    cin >> size;

    vector<char> arr[2];

    cout << "Enter preorder and inorder arrays:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        arr[i].resize(size);
        for (int j = 0; j < size; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        table[arr[1][i]] = i;
    }

    Node* head = buildTree(arr, 0, size - 1);

    preOrder(head);

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
