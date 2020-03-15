// HackerrankMaxArraySum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubsetSum(vector<int>& arr)
{
    vector<int> dp(arr.size());

    if (arr.size() == 1)
        return arr[0];

    dp[0] = arr[0];
    if (arr.size() == 2)
        return max(arr[0], arr[1]);

    dp[1] = max(arr[0], arr[1]);

    int maxVal = INT_MIN;
    for (int i = 2; i < arr.size(); ++i)
    {
        dp[i] = max(dp[i - 2] + arr[i], max(dp[i - 1], arr[i]));
    }

    return dp[arr.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }

    std::cout << maxSubsetSum(input);

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
