// LeftViewOfBT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int data;

	Node* left;
	Node* right;

	Node() : left(nullptr), right(nullptr), data(-1)
	{

	}
};

void leftView(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		int nodecount = q.size();
		bool flag_first = true;
		while (nodecount--)
		{
			Node* temp = q.front();
			q.pop();
			if (flag_first)
			{
				cout << temp->data << " ";
				flag_first = false;
			}
			if (temp->left)q.push(temp->left);
			if (temp->right)q.push(temp->right);
		}
	}
	cout << endl;
}

int main()
{

	Node* one = new Node();
	one->data = 1;
	
	Node* two = new Node();
	two->data = 2;
	
	Node* three = new Node();
	three->data = 3;
	
	Node* four = new Node();
	four->data = 4;

	Node* five = new Node();
	five->data = 5;
	
	Node* six = new Node();
	six->data = 6;

	Node* seven = new Node();
	seven->data = 7;

	Node* eight = new Node();
	eight->data = 8;

	Node* nine = new Node();
	nine->data = 9;

	//one->left = two;
	//one->right = three;

	//two->left = four;
	//two->right = five;

	//four->right = six;
	//
	//six->left = seven;
	//six->right = eight;

	//eight->left = nine;

	one->left = two;
	one->right = three;

	two->left = four;

	three->left = five;

	five->left = six;


	leftView(one);


	return 0;
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
