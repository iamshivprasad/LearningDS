// LinkedListAddNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
	int data;
	struct Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


Node* Insert(Node* head, int val)
{
	Node* newNode = new Node(val);

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

	return head;
}
// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
	if (first == NULL || second == NULL)
	{
		return NULL;
	}

	int  temp, sum = 0, firstVal = 0, secondVal = 0;
	int carry = 0;
	Node* resHead = NULL, * resTail = NULL;
	bool isContinue = true;
	while (first != NULL || second != NULL)
	{
		if (first != NULL)
		{
			firstVal = first->data;
			first = first->next;
		}
		else
		{
			firstVal = 0;
		}

		if (second != nullptr)
		{
			secondVal = second->data;
			second = second->next;
		}
		else
		{
			secondVal = 0;
		}

		temp = firstVal + secondVal + carry;
		sum = temp % 10;
		carry = temp / 10;

		Node* tempNode = new Node(sum);
		if (resHead == NULL)
		{
			resTail = resHead = tempNode;
		}
		else
		{
			resTail->next = tempNode;
			resTail = tempNode;
		}

	}

	if (carry != 0)
	{
		Node* tempNode = new Node(carry);
		resTail->next = tempNode;
		resTail = tempNode;
	}

	return resHead;
}

int main()
{
	std::cout << "Enter the size and elements of list1" << std::endl;

	int n;
	std::cin >> n;

	Node* head1 = nullptr, * head2 = nullptr;

	int val;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> val;
		head1 = Insert(head1, val);
	}

	std::cout << "Enter the size and elements of list2" << std::endl;

	val = 0;
	int m;
	std::cin >> m;

	for (int i = 0; i < m; ++i)
	{
		std::cin >> val;
		head2 = Insert(head2, val);
	}

	Node* result = addTwoLists(head1, head2);

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
