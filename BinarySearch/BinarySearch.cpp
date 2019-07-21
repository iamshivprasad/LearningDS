// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool BinarySearch(int* a, int left, int right, int key)
{
    if (left >= right)
        return false;

    int mid = left + (right - left) / 2;

    if (a[mid] == key)
        return true;

    if (a[mid] < key)
        return BinarySearch(a, mid + 1, right - 1, key);

    return BinarySearch(a, 0, mid - 1, key);
}

int main()
{
    int n;
    std::cout << "Enter the size of array: \n";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the array elements: \n";

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int key;
    cout << "Enter element to be searched: \n";
    cin >> key;

    bool res = BinarySearch(arr, 0, n-1, key);

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
