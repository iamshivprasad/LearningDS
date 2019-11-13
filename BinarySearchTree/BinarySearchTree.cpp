// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BSTImpl.h"

#include<map>

Node* Insert(Node* root, int val)
{
    if (root == nullptr)
    {
        root = new Node();
        root->data = val;
    }
    else if(val > root->data)
    {
        root->right = Insert(root->right, val);
    }
    else if (val <= root->data)
    {
        root->left = Insert(root->left, val);
    }
    return root;
}

int main()
{

    // Test Insert

    //BSTImpl obj;
    //obj.Insert(50);
    //obj.Insert(10);
    //obj.Insert(15);
    //obj.Insert(60);
    //obj.Insert(51);

    // Test Search

    //if (obj.Search(51))
    //{
    //    std::cout << "Gotcha!!!";
    //}
    //else
    //{
    //    std::cout << "Could not find 55";
    //}

    // Test IsBST()

    Node* root = new Node();
    root->data = 1;
    root->left = nullptr;
    root->right = nullptr;

    Node* tmp = new Node();
    tmp->data = 2;
    tmp->left = nullptr;
    tmp->right = nullptr;

    root->left = tmp;

    tmp = new Node();
    tmp->data = 3;
    tmp->left = nullptr;
    tmp->right = nullptr;

    root->right = tmp;

    tmp = new Node();
    tmp->data = 5;

    root->left->left = tmp;

    tmp = new Node();
    tmp->data = 10;
    root->right->left = tmp;

    tmp = new Node();
    tmp->data = 44;

    root->left->left->left = tmp;

    BSTImpl obj;

    //if (obj.IsBST(root))
    //    std::cout << "Given tree is BST.";

    //else
    //    std::cout << "Not a BST";

    //int h = obj.FindHeight(root);

    //obj.BreadtheFirstTraversal(root);

    obj.Delete(root, 44);
    getchar();
}
