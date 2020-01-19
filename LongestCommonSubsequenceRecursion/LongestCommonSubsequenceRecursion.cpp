// LongestCommonSubsequenceRecursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s1, s2;
int longestCommonSubsequence(int i, int j)
{
    if (i == s1.length() || j == s2.length())
        return 0;

    if (s1[i] == s2[j])
        return 1 + longestCommonSubsequence(i + 1, j + 1);

    else
        return std::max(longestCommonSubsequence(i + 1, j), longestCommonSubsequence(i, j + 1));
}

int lcsDynamic()
{
    vector <vector<int>> table;
    table.resize(s1.length() + 1);

    for (int i = 0; i < table.size(); ++i)
    {
        table[i].resize(s2.length() + 1);
    }

    int max = 0;

    for (int i = 1; i < table.size(); ++i)
    {
        for (int j = 1; j < table[i].size(); ++j)
        {
            if (s1[i-1] == s2[j-1])
            {
                table[i][j] = 1 + table[i - 1][j - 1];
            }
            else
            {
                table[i][j] = std::max(table[i][j - 1], table[i - 1][j]);
            }

            if (table[i][j] > max)
                max = table[i][j];
        }
    }

    return max;
}

int main()
{
    std::cout << "Enter two strings: \n";

    cin >> s1 >> s2;

    std::cout << lcsDynamic();
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
