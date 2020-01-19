// HackerrankMinMax.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxMin(int k, vector<int> arr)
{
    sort(arr.begin(), arr.end());

    int min = INT_MAX;
    for (int i = 0; i <= arr.size() - k; ++i)
    {
        if (arr[i + (k - 1)] - arr[i] < min)
        {
            min = arr[i + (k - 1)] - arr[i];
        }
    }

    return min;
}

int main()
{
    std::cout << "Enter size, k and array elements: \n";

    int size, k;
    cin >> size >> k;

    vector<int> arr(size);

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << maxMin(k, arr);
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
