// LCShortestPathBinaryMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int neighbours[][8] = {{ -1,  0,  1, -1,  1, -1, 0, 1},
                       { -1, -1, -1,  0,  0,  1, 1, 1} };



struct Point
{
    int x;
    int y;
    int score;
};


bool isValid(int x, int y, const vector<vector<int>>& grid)
{
    if (x < 0 || x > grid.size() - 1 || 
        y < 0 || y > grid.size() - 1 || 
        grid[x][y] == 1 )
        return false;

    return true;
}

int shortestpathbinarymatrix(vector<vector<int>>& grid) 
{
    Point start{ 0, 0, 0 };

    queue<Point> q;
    q.push(start);

    bool** visited = new bool* [grid.size()]();
    for (int i = 0; i < grid.size(); ++i)
    {
        visited[i] = new bool[grid.size()]();
    }

    while (!q.empty())
    {
        Point t = q.front();

        if (t.x == grid.size() - 1 && t.y == grid.size())
        {
            // clean up visited
            return t.score;
        }

        q.pop();

        visited[t.x][t.y] = true;

        for (int i = 0; i < 8; ++i)
        {
            int newX = t.x + neighbours[0][i];
            int newY = t.y + neighbours[1][i];
            if (isValid(newX, newX, grid) && !visited[newX][newY])
            {
                q.push({ newX, newY, t.score + 1 });
            }
        }
    }

    // clean up visited

    return -1;
}

int main()
{
    std::cout << "Hello World!\n";

    vector<vector<int>> grid = { {0,0,0}, {1,1,0}, {1,1,0} };



    cout << shortestpathbinarymatrix(grid) << endl;

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
