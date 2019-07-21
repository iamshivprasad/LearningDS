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
        root->nVal = val;
    }
    else if(val > root->nVal)
    {
        root->pRight = Insert(root->pRight, val);
    }
    else if (val <= root->nVal)
    {
        root->pLeft = Insert(root->pLeft, val);
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
    root->nVal = 1;
    root->pLeft = nullptr;
    root->pRight = nullptr;

    Node* tmp = new Node();
    tmp->nVal = 2;
    tmp->pLeft = nullptr;
    tmp->pRight = nullptr;

    root->pLeft = tmp;

    tmp = new Node();
    tmp->nVal = 3;
    tmp->pLeft = nullptr;
    tmp->pRight = nullptr;

    root->pRight = tmp;

    tmp = new Node();
    tmp->nVal = 5;

    root->pLeft->pLeft = tmp;

    tmp = new Node();
    tmp->nVal = 10;
    root->pRight->pLeft = tmp;

    tmp = new Node();
    tmp->nVal = 44;

    root->pLeft->pLeft->pLeft = tmp;

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
