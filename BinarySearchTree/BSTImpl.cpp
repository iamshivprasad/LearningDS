#include "BSTImpl.h"
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;



BSTImpl::BSTImpl(): m_pRoot(nullptr)
{
}


BSTImpl::~BSTImpl()
{
    delete m_pRoot;
    m_pRoot = nullptr;
}

//void BSTImpl::Insert(int nVal)
//{
//    Node* pTmp = new Node();
//    pTmp->nVal = nVal;
//    pTmp->pLeft = nullptr;
//    pTmp->pRight = nullptr;
//
//    // First element
//    if (m_pRoot == nullptr)
//    {
//        m_pRoot = pTmp;
//    }
//    else
//    {
//        Node** tmp = &m_pRoot;
//        while (*tmp)
//        {
//            if (nVal > (*tmp)->nVal)
//            {
//                tmp = &(*tmp)->pRight;
//            }
//            else
//            {
//                tmp = &(*tmp)->pLeft;
//            }
//        }
//
//        *tmp = new Node();
//        (*tmp)->nVal = nVal;
//    }
//
//}

void BSTImpl::Insert(int nVal)
{
    Node* pTmp = new Node();
    pTmp->data = nVal;
    pTmp->left = nullptr;
    pTmp->right = nullptr;

    // First element
    if (m_pRoot == nullptr)
    {
        m_pRoot = pTmp;
    }
    else
    {
        Node** tmp = &m_pRoot;
        while (*tmp)
        {
            if (nVal > (*tmp)->data)
            {
                tmp = &((*tmp)->right);
            }
            else
            {
                tmp = &((*tmp)->left);
            }
        }

        *tmp = new Node();
        (*tmp)->data = nVal;
    }

}

bool BSTImpl::Search(int nVal)
{

    if (m_pRoot == nullptr)
        return false;

    Node* tmp = m_pRoot;

    bool bIsFound = false;
    while (tmp != nullptr)
    {
        if (tmp->data == nVal)
        {
            bIsFound = true;
            break;
        }
        else if (nVal > tmp->data)
        {
            tmp = tmp->right;
        }
        else if (nVal < tmp->data)
        {
            tmp = tmp->left;
        }
    }

    return bIsFound;
}

void BSTImpl::Display()
{
}

bool BSTImpl::IsBST(Node* root)
{
    if (root == nullptr)
    {
        return true;
    }

    if(IsLeftSubtreeLessorThanRoot(root->left, root->data) &&
       IsRightSubtreeGreaterThanRoot(root->right, root->data) &&
       IsBST(root->left) && 
       IsBST(root->right))
    {
        return true;
    }

    return false;
}

int BSTImpl::FindHeight(Node* root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int heightOfLeftSubtree = FindHeight(root->left);
    int heightOfRightSubtree = FindHeight(root->right);

    int height = __max(heightOfLeftSubtree, heightOfRightSubtree) + 1;

    return height;
}

void BSTImpl::BreadtheFirstTraversal(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node*> tobeVisited;
    tobeVisited.push(root);

    while (!tobeVisited.empty())
    {
        Node*& top = tobeVisited.front();

        if (top != nullptr)
        {
            std::cout << top->data << "\n\r";

            tobeVisited.push(top->left);
            tobeVisited.push(top->right);
        }

        tobeVisited.pop();
    }
}

Node* BSTImpl::FindMin(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root;
}

Node* BSTImpl::Delete(Node* root, int nVal)
{
    if (root == nullptr)
        return false;
    else if (nVal > root->data)
        root->right = Delete(root->right, nVal);
    else if(nVal < root->data)
        root->left = Delete(root->left, nVal);
    else
    {
        /*  case 1: no child
            case 2: with one child
            case 3: with 2 children
        */

        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
            return root;
        }
        else if (root->left == nullptr)
        {
            Node* tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
        else if (root->right == nullptr)
        {
            Node* tmp = root;
            root = root->left;
            delete tmp;
        }
        else
        {
            Node* minNode = FindMin(root->right);
            root->data = minNode->data;

            root->right = Delete(root->right, minNode->data);
        }
    }

}



bool BSTImpl::IsLeftSubtreeLessorThanRoot(Node* root, int nVal)
{
    if (root == nullptr)
        return true;

    if (root->data < nVal &&
        IsLeftSubtreeLessorThanRoot(root->left, nVal) &&
        IsRightSubtreeGreaterThanRoot(root->right, nVal))
    {
        return true;
    }

    return false;
}

bool BSTImpl::IsRightSubtreeGreaterThanRoot(Node* root, int nVal)
{
    if (root == nullptr)
        return true;

    if (root->data > nVal &&
        IsRightSubtreeGreaterThanRoot(root->left, nVal) &&
        IsRightSubtreeGreaterThanRoot(root->right, nVal))
    {
        return true;
    }

    return false;
}
