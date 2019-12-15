// MinimumStepsToReachTarget.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
using namespace std;

const int N = 30;

struct Cell
{
	int x;
	int y;
	int distance;

public:

	Cell(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

bool isInside(int x, int y)
{
	if (x > 0 && x <= N && y > 0 && y <= N)
		return true;

	return false;
}

int minStepToReachTarget(int start[], int end[])
{
	int possibleX[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int possibleY[] = {-1, -2, -2, -1, 1, 2, 2, 1};

	queue<Cell> q;
	q.push(Cell(start[0], start[1], 0));

	bool visited[N + 1][N + 1];

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			visited[i][j] = false;

	visited[start[0]][start[1]] = true;

	while (!q.empty())
	{
		Cell currCell = q.front();
		q.pop();

		if (currCell.x == end[0] && currCell.y == end[1])
		{
			return currCell.distance;
		}

		for(int i = 0; i < 8; ++i)
		{
			int x = currCell.x + possibleX[i];
			int y = currCell.y + possibleY[i];

			if (isInside(x, y) && !visited[x][y])
			{
				visited[x][y] = true;

				q.push(Cell(x, y, currCell.distance + 1));
			}

		}
	}

}

int main()
{
	int knightPos[] = { 1, 1 };
	int targetPos[] = { 30, 30 };
	cout << minStepToReachTarget(knightPos, targetPos);
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
