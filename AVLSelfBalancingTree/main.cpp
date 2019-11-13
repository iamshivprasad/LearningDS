#include <iostream>
#include "AVLTree.h"

using namespace std;

int main(int argc, char* argv[])
{
    AVLTree<int> myTree;
    myTree.insert(20);
    myTree.insert(10);
    myTree.insert(30);
    myTree.insert(8);
    myTree.insert(7);

    return 0;
}