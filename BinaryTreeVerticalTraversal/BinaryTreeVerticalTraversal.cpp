// BinaryTreeVerticalTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;


struct Node
{
	int data;

	Node* left;
	Node* right;

public:

	Node(int n) : data(n), left(NULL), right(NULL)
	{

	}
};

// using recursion

//void PopulateHashTable(Node* root, int distance, map<int, vector<int>>& hashTable)
//{
//	if (root == NULL)
//		return;
//
//	hashTable[distance].push_back(root->data);
//
//	if (root->left != NULL)
//	{
//		PopulateHashTable(root->left, distance - 1, hashTable);
//	}
//
//	if (root->right != NULL)
//	{
//		PopulateHashTable(root->right, distance + 1, hashTable);
//
//	}
//}
//
//void verticalOrder(Node* root)
//{
//	map<int, vector<int>> hashTable;
//
//	PopulateHashTable(root, 0, hashTable);
//
//	map<int, vector<int>>::iterator itr;
//	for (itr = hashTable.begin(); itr != hashTable.end(); ++itr)
//	{ 
//		for (int i : itr->second)
//		{
//			cout << i << " ";
//		}
//	}
//
//}

// using level order traversal
void verticalOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	} 

	queue<pair<Node*, int>> values;
	map<int, vector<int>> hashTable;

	values.push({ root, 0 });
	while (!values.empty())
	{
		Node* temp = values.front().first;
		int hd = values.front().second;
		hashTable[hd].push_back(temp->data);

		values.pop();

		if (temp->left != NULL)
		{
			values.push({ temp->left, hd - 1 });
		}

		if (temp->right != NULL)
		{
			values.push({ temp->right, hd + 1});
		}
	}

	map<int, vector<int>>::iterator itr;
	for (itr = hashTable.begin(); itr != hashTable.end(); ++itr)
	{
		for (int i : itr->second)
		{
			cout << i << " ";
		}
	}
}

int main()
{
	//Node* one = new Node(1);

	//Node* two = new Node(2);

	//Node* three = new Node(3);

	//Node* four = new Node(4);

	//Node* five = new Node(5);

	//Node* six = new Node(6);

	//Node* seven = new Node(7);

	//Node* eight = new Node(8);

	//Node* nine = new Node(9);

	//one->left = two;
	//one->right = three;

	//two->left = four;
	//two->right = five;

	//three->left = six;
	//three->right = seven;

	//verticalOrder(one);

	// delete the nodes

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
