// SpiralTraversalMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void SpiralTraversal(int mat[][4], int m, int n)
{
    int k = 0;
    int l = 0;

    while (k < m && l < n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << mat[k][i] << " ";
        }

        k++;

        for (int i = k; i < m; i++)
        {
            cout << mat[i][n - 1] << " ";
        }
        
        n--;

        if (k < m)
        {
            for (int i = n - 1; i >= 0; --i)
            {
                cout << mat[m - 1][i] << " ";
            }
            m--;
        }

        if (l < n)
        {
            for (int i = m - 1; i >= k; --i)
            {
                cout << mat[i][l] << " ";
            }
            l++;
        }
    }
}

int main()
{

    int mat[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}};

    SpiralTraversal(mat, 4, 4);

    getchar();
}

