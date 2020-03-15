// HackerrankPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int pairs(int k, vector<int> arr)
{
    unordered_set<int> table;
    sort(arr.begin(), arr.end());

    int count = 0;
    for (auto i : arr)
    {
        if (table.find(i - k) != table.end())
            ++count;

        table.insert(i);
    }

    //sort(arr.begin(), arr.end());

    //int count = 0;
    //for (int i = 0; i <= arr.size() - k; ++i)
    //{
    //    int j = i + 1;
    //    while (j < arr.size() && arr[j] <= arr[i] + k)
    //    {
    //        if (arr[j] - arr[i] == k)
    //        {
    //            ++count;
    //        }
    //        ++j;
    //    }
    //}

    return count;
}

int main()
{
    std::cout << "Enter the size and target difference:\n";

    int size, k;
    cin >> size >> k;

    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << pairs(k, arr);
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
