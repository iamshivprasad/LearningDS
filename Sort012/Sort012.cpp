// Sort012.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void swap(int& left, int& right)
{
    left = left ^ right;
    right = right ^ left;
    left = left ^ right;
}

void Sort(int*& arr, int size)
{
    int low = 0;
    int mid = 0;
    int high = size - 1;

    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
        
        case 1:
            mid++;
            break;

        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;

        default:
            break;
        }
    }
}

int main()
{
    std::cout << "Enter the size of the array: \n";

    int size;
    cin >> size;

    cout << "Enter the array:\n";
    int* arr = new int[size]();

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    Sort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }

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
