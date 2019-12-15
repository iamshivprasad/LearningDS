// DiameterOfBT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int data;

	Node* left;
	Node* right;
};

int height(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node* root)
{
	if (root == NULL)
		return true;

	int hleft = height(root->left);
	int hright = height(root->right);

	if (abs(hleft - hright) <= 1 && 
		isBalanced(root->left) &&
		isBalanced(root->right))
		return true;

	return false;
}

/* Return max of following three
 1) Diameter of left subtree
 2) Diameter of right subtree
 3) Height of left subtree + height of right subtree + 1 */

int diameter(Node* root)
{
	if (root == NULL)
		return 0;

	int lheight = height(root->left);
	int rheight = height(root->right);

	int ldiameter = diameter(root->left);
	int rdiameter = diameter(root->left);

	return max(1 + lheight + rheight, max(ldiameter, rdiameter));
}

int main()
{
    std::cout << "Hello World!\n";
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
