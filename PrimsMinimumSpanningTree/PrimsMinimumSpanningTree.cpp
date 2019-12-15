// PrimsMinimumSpanningTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define I INT_MAX
int countOfVertices = 8;
int cost[8][8] = { I,  I,  I,  I,  I,  I,  I, I,
				  I,  I, 25,  I,  I,  I,  5, I,
				  I, 25,  I, 12,  I,  I,  I, 10,
				  I,  I, 12,  I,  8,  I,  I, I,
				  I,  I,  I,  8,  I, 16,  I, 14,
				  I,  I,  I,  I, 16,  I, 20, 18,
				  I,  5,  I,  I,  I, 10,  I, I,
				  I,  I, 10,  I, 14, 18,  I, I };

int near[8] = { I, I, I, I, I, I, I, I };

int t[2][6];


void FindMST()
{

	// Finding the min edge
	int min = I;
	int u = 0, v = 0;
	for (int i = 0; i < countOfVertices; ++i)
	{
		for (int j = i; j < countOfVertices; ++j)
		{
			if (cost[i][j] < min)
			{
				min = cost[i][j];
				u = i;
				v = j;
			}
		}
	}

	t[0][0] = u;
	t[1][0] = v;

	near[u] = 0;
	near[v] = 0;
	
	// Filling the nodes closer to u and v
	for (int i = 1; i < countOfVertices; ++i)
	{
		if (near[i] != 0)
		{
			if (cost[i][u] < cost[i][v])
			{
				near[i] = u;
			}
			else
				near[i] = v;
		}
	}

	int k;
	for (int i = 1; i < countOfVertices - 1; ++i)
	{
		min = I;
		// find min from the near array
		for (int j = 0; j < countOfVertices; ++j)
		{
			if (near[j] != 0)
			{
				if (cost[j][near[j]] < min)
				{
					min = cost[j][near[j]];
					k = j;
				}
			}
		}

		t[0][i] = k;
		t[1][i] = near[k];

		near[k] = 0;

		// update near array
		for (int i = 1; i < countOfVertices; ++i)
		{
			if (near[i] != 0)
			{
				if (cost[i][k] < cost[i][near[j]])
				{
					near[i] = k;
				}
			}
		}

	}

}

int main()
{


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
