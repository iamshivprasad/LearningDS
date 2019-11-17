// BTConnectNodesAtSameLevel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <queue>

using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* nextRight;
	Node(int x) {
		data = x;
		left = right = NULL;
		nextRight = NULL;
	}
};

void connect(struct Node* p);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
void printSpecial(Node* root)
{
	if (root == NULL)
		return;
	Node* node = root;
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->nextRight;
	}
	if (root->left)
		printSpecial(root->left);
	else
		printSpecial(root->right);
}

void inorder(Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
	int t;
	scanf("%d", &t);
		while (t--)
		{
			map<int, Node*> m;
			int n;
			scanf("%d", &n);
			struct Node* root = NULL;
			struct Node* child;
			while (n--)
			{
				Node* parent;
				char lr;
				int n1, n2;
				scanf("%d %d %c", &n1, &n2, &lr);
				if (m.find(n1) == m.end())
				{
					parent = new Node(n1);
					m[n1] = parent;
					if (root == NULL)
						root = parent;
				}
				else
					parent = m[n1];
				child = new Node(n2);
				if (lr == 'L')
					parent->left = child;
				else
					parent->right = child;
				m[n2] = child;
			}
			connect(root);
			printSpecial(root);
			cout << endl;
			inorder(root);
			cout << endl;
		}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node* p)
{
	if (p == NULL)
		return;

	queue<Node*> q1, q2;
	q1.push(p);

	while (!q1.empty())
	{
		q2 = q1;
		Node* prev = q2.front();
		prev->nextRight = NULL;
		while (!q2.empty())
		{
			q2.pop();

			if (!q2.empty())
			{
				prev->nextRight = q2.front();

				if (prev->left != NULL)
					q1.push(prev->left);

				if (prev->right != NULL)
					q1.push(prev->right);

				prev = q2.front();
			}
			else
			{
				prev->nextRight = NULL;

				if (prev->left != NULL)
					q1.push(prev->left);

				if (prev->right != NULL)
					q1.push(prev->right);
			}

			q1.pop();
		}
	}

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
