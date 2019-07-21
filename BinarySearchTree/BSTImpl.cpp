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
    pTmp->nVal = nVal;
    pTmp->pLeft = nullptr;
    pTmp->pRight = nullptr;

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
            if (nVal > (*tmp)->nVal)
            {
                tmp = &((*tmp)->pRight);
            }
            else
            {
                tmp = &((*tmp)->pLeft);
            }
        }

        *tmp = new Node();
        (*tmp)->nVal = nVal;
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
        if (tmp->nVal == nVal)
        {
            bIsFound = true;
            break;
        }
        else if (nVal > tmp->nVal)
        {
            tmp = tmp->pRight;
        }
        else if (nVal < tmp->nVal)
        {
            tmp = tmp->pLeft;
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

    if(IsLeftSubtreeLessorThanRoot(root->pLeft, root->nVal) &&
       IsRightSubtreeGreaterThanRoot(root->pRight, root->nVal) &&
       IsBST(root->pLeft) && 
       IsBST(root->pRight))
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

    int heightOfLeftSubtree = FindHeight(root->pLeft);
    int heightOfRightSubtree = FindHeight(root->pRight);

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
            std::cout << top->nVal << "\n\r";

            tobeVisited.push(top->pLeft);
            tobeVisited.push(top->pRight);
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
    
    while (root->pLeft != nullptr)
    {
        root = root->pLeft;
    }

    return root;
}

Node* BSTImpl::Delete(Node* root, int nVal)
{
    if (root == nullptr)
        return false;
    else if (nVal > root->nVal)
        root->pRight = Delete(root->pRight, nVal);
    else if(nVal < root->nVal)
        root->pLeft = Delete(root->pLeft, nVal);
    else
    {
        /*  case 1: no child
            case 2: with one child
            case 3: with 2 children
        */

        if (root->pLeft == nullptr && root->pRight == nullptr)
        {
            delete root;
            root = nullptr;
            return root;
        }
        else if (root->pLeft == nullptr)
        {
            Node* tmp = root;
            root = root->pRight;
            delete tmp;
            return root;
        }
        else if (root->pRight == nullptr)
        {
            Node* tmp = root;
            root = root->pLeft;
            delete tmp;
        }
        else
        {
            Node* minNode = FindMin(root->pRight);
            root->nVal = minNode->nVal;

            root->pRight = Delete(root->pRight, minNode->nVal);
        }
    }

}

bool BSTImpl::IsLeftSubtreeLessorThanRoot(Node* root, int nVal)
{
    if (root == nullptr)
        return true;

    if (root->nVal < nVal &&
        IsLeftSubtreeLessorThanRoot(root->pLeft, nVal) &&
        IsRightSubtreeGreaterThanRoot(root->pRight, nVal))
    {
        return true;
    }

    return false;
}

bool BSTImpl::IsRightSubtreeGreaterThanRoot(Node* root, int nVal)
{
    if (root == nullptr)
        return true;

    if (root->nVal > nVal &&
        IsRightSubtreeGreaterThanRoot(root->pLeft, nVal) &&
        IsRightSubtreeGreaterThanRoot(root->pRight, nVal))
    {
        return true;
    }

    return false;
}
