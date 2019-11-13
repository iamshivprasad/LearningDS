#pragma once

struct Node
{
    int data;

    Node* left;
    Node* right;

    Node() : left(nullptr), right(nullptr), data(-1)
    {

    }
};

class BSTImpl
{
public:
    BSTImpl();
    ~BSTImpl();

    void Insert(int nVal);

    bool Search(int nVal);

    void Display();

    bool IsBST(Node* root);

    int FindHeight(Node* root);

    void BreadtheFirstTraversal(Node* root);

    Node* FindMin(Node* root);

    Node* Delete(Node* root, int nVal);

	void LeftViewOfTree();

private:

    bool IsLeftSubtreeLessorThanRoot(Node* root, int nVal);
    bool IsRightSubtreeGreaterThanRoot(Node* root, int nVal);

private:

    Node* m_pRoot;
};

