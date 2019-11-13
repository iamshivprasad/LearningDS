// LLFlatteni\ng.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* bottom;

	Node(int x) {
		data = x;
		next = NULL;
		bottom = NULL;
	}

};

Node* sortedMerge(Node* left, Node* right)
{
	if (left == NULL && right == NULL)
	{
		return NULL;
	}

	Node* mergedListHead = NULL;
	Node* mergedListTail = NULL;
	Node* lptr = left;
	Node* rptr = right;

	while (lptr != NULL && rptr != NULL)
	{
		if (lptr->data > rptr->data)
		{
			if (mergedListHead == NULL)
			{
				mergedListHead = rptr;
				mergedListTail = rptr;
			}
			else
			{
				mergedListTail->bottom = rptr;
				mergedListTail = rptr;
			}
			rptr = rptr->bottom;
		}
		else
		{
			if (mergedListHead == NULL)
			{
				mergedListHead = lptr;
				mergedListTail = lptr;
			}
			else
			{
				mergedListTail->bottom = lptr;
				mergedListTail = lptr;

			}
			lptr = lptr->bottom;
		}
	}

	if (rptr != NULL)
	{
		mergedListTail->bottom = rptr;
	}

	if (lptr != NULL)
	{
		mergedListTail->bottom = lptr;

	}

	
	return mergedListHead;
}


void splitList(Node* root, Node*& first, Node*& second)
{
	Node* fast;
	Node* slow;
	slow = root;
	fast = root->bottom;

	while (fast != NULL) {
		fast = fast->bottom;
		if (fast != NULL) {
			slow = slow->bottom;
			fast = fast->bottom;
		}
	}

	first = root;
	second = slow->bottom;
	slow->bottom = NULL;
}

Node* mergeSort(Node* root)
{
	if (root == NULL || root->bottom == NULL)
	{
		return root;
	}

	Node* firstHalf = NULL;
	Node* secondHalf = NULL;

	splitList(root, firstHalf, secondHalf);

	firstHalf = mergeSort(firstHalf);
	secondHalf = mergeSort(secondHalf);

	return sortedMerge(firstHalf, secondHalf);
}

Node* flatten(Node* root)
{
	if(root == NULL)
		return NULL;

	Node* current = root;
	while (current != NULL)
	{
		current = mergeSort(current);

		current = current->next;
	}

	current = root->next;

	while (root != NULL && current != NULL)
	{
		root = sortedMerge(root, current);

		current = current->next;
	}


	return root;
}

void printList(Node* Node)
{
	while (Node != NULL)
	{
		printf("%d ", Node->data);
		Node = Node->bottom;
	}
}

Node* createInputStructure(vector<int> sizes, vector<int> elements)
{
	Node* root = NULL, *tail = NULL;
	int startSize = 0;
	for (auto& size : sizes)
	{
		Node* tempHead = NULL, *tempBottom = NULL, *tempTail = NULL;

		for (int i = startSize; i < startSize + size; ++i)
		{
			Node* newNode = new Node(elements[i]);
			if (tempHead == NULL)
			{
				tempHead = newNode;
				tempBottom = newNode;
			}
			else
			{
				tempBottom->bottom = newNode;
				tempBottom = newNode;
			}

		}

		if (root == NULL)
		{
			root = tempHead;
			tail = tempHead;
		}
		else
		{
			tail->next = tempHead;
			tail = tempHead;
		}

		startSize += size;
	}

	return root;
}

int main()
{
	std::cout << "Enter the number of heads:" << std::endl;

	int numHead = 0;
	std::cin >> numHead;

	std::vector<int> sizeArray(numHead);

	std::cout << "Enter the sizes of each chain: " << std::endl;
	for (int i = 0; i < numHead; ++i)
	{
		std::cin >> sizeArray[i];
	}


	int totalNumOfElements = std::accumulate(sizeArray.begin(), sizeArray.end(), 0);
	std::vector<int> inputElements(totalNumOfElements);
	std::cout << "Enter the elements: " << std::endl;
	for (int i = 0; i < totalNumOfElements; ++i)
	{
		cin >> inputElements[i];
	}

	Node* head = createInputStructure(sizeArray, inputElements);

	head = flatten(head);

	printList(head);

	return 0;

}
