#include <algorithm>

template<typename T>
struct Node
{
    T val;
    int height;

    Node* lc;
    Node* rc;
};

template<typename T>
class AVLTree
{
public:
    
    AVLTree() : m_root(nullptr){}
    
    void insert(T val);

private:

    Node<T>* m_root;

    Node<T>* internalInsert(Node<T> *node, int val);

    int GetHeight(Node<T>* node);

    int BalanceFactor(Node<T>* node);

    Node<T>* LLRotation(Node<T>* node);
    Node<T>* LRRotation(Node<T>* node);
    Node<T>* RLRotation(Node<T>* node);
    Node<T>* RRRotation(Node<T>* node);
};

template<typename T>
void AVLTree<T>::insert(T val)
{
    m_root = internalInsert(m_root, val);

    //Node<T>* newNode = new Node<T>();
    //newNode->val = val;
   
    //if (m_root == nullptr)
    //{
    //    m_root = newNode;    

    //}
    //else
    //{
    //    Node<T>** tmp = &m_root;

    //    while (*tmp)
    //    {
    //        if (val > (*tmp)->val)
    //        {
    //            tmp = &(*tmp)->rc;
    //        }
    //        else
    //        {
    //            tmp = &(*tmp)->lc;
    //        }
    //    }

    //    *tmp = newNode;
    //}


}

template<typename T>
inline Node<T>* AVLTree<T>::internalInsert(Node<T>* node, int val)
{
    if (node == nullptr)
    {
        node = new Node<T>();
        node->height = 0;
        node->val = val;
        return node;
    }
    else if (val > node->val)
        node->rc = internalInsert(node->rc, val);
    else
        node->lc = internalInsert(node->lc, val);

    node->height = GetHeight(node);

    if (BalanceFactor(node) == 2 && BalanceFactor(node->lc) == 1)
        return LLRotation(node);
    else if (BalanceFactor(node) == 2 && BalanceFactor(node->lc) == -1)
        return LRRotation(node);
    else if (BalanceFactor(node) == -2 && BalanceFactor(node->lc) == -1)
        return RRRotation(node);
    else if (BalanceFactor(node) == -2 && BalanceFactor(node->lc) == 1)
        return RLRotation(node);


    return node;
}

template<typename T>
inline int AVLTree<T>::GetHeight(Node<T>* node)
{
    if (node == nullptr)
        return -1;

    int nLeftH = GetHeight(node->lc);
    int nRightH = GetHeight(node->rc);


    return std::max(nLeftH, nRightH) + 1;
}

template<typename T>
inline int AVLTree<T>::BalanceFactor(Node<T>* node)
{
    int hl = node->lc ? node->lc->height : 0;
    int hr = node->rc ? node->rc->height : 0;

    return hl - hr;
}

template<typename T>
inline Node<T>* AVLTree<T>::LLRotation(Node<T>* node)
{
    Node<T>* pl = node->lc;
    Node<T>* plr = pl->rc;

    pl->rc = node;
    node->lc = plr;
    
    node->height = GetHeight(node);
    pl->height = GetHeight(pl);

    if (m_root == node)
        m_root = pl;

    return pl;
}

template<typename T>
inline Node<T>* AVLTree<T>::LRRotation(Node<T>* node)
{
    Node<T>* pl = node->lc;
    Node<T>* plr = pl->rc;

    pl->rc = plr->lc;
    node->lc = plr->rc;

    plr->rc = node;
    plr->lc = pl;

    pl->height = GetHeight(pl);
    node->height = GetHeight(node);
    plr->height = GetHeight(node);

    if (m_root == node)
        m_root = plr;

    return plr;
}

template<typename T>
inline Node<T>* AVLTree<T>::RLRotation(Node<T>* node)
{
    return NULL;
}

template<typename T>
inline Node<T>* AVLTree<T>::RRRotation(Node<T>* node)
{
    return NULL;
}

