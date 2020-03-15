// IsBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
	int data;
	Node* right;
	Node* left;

	Node(int x) {
		data = x;
		right = NULL;
		left = NULL;
	}
}; 

bool IsTreeLesserThanRoot(Node * root, int val)
{
	if (root == NULL || (root->data <= val && IsTreeLesserThanRoot(root->left, val) &&
		IsTreeLesserThanRoot(root->right, val)))
	{
		return true;
	}
	else
		return false;
}

bool IsTreeGreaterThanRoot(Node* root, int val)
{
	if ( root == NULL || (root->data > val&& IsTreeGreaterThanRoot(root->left, val) &&
		IsTreeGreaterThanRoot(root->right, val)))
	{
		return true;
	}
	else
		return false;
}

bool isBST(Node* root) {

	if (root == NULL)
		return true;

	if (IsTreeLesserThanRoot(root->left, root->data) &&
		IsTreeGreaterThanRoot(root->right, root->data) &&
		isBST(root->left) && isBST(root->right))
	{
		return true;
	}
	else
		return false;

}

bool isBSTOptimal(Node* root, int l, int r)
{
	if (root == NULL)
		return true;

	if (root->data > l && root->data < r &&
		isBSTOptimal(root->left, l, root->data) && isBSTOptimal(root->right, root->data, r))
	{
		return true;
	}

	return false;
}

int main()
{
	Node* one = new Node(1);

	Node* two = new Node(2);

	Node* three = new Node(3);

	Node* four = new Node(4);

	Node* five = new Node(5);

	Node* six = new Node(6);

	Node* seven = new Node(7);

	Node* eight = new Node(8);

	Node* nine = new Node(9);

	two->left = one;

	two->right = three;

	//bool res = isBST(one);
	bool res = isBSTOptimal(one, INT_MAX, INT_MIN);


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
