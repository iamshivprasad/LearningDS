// InversionArrayMergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int Merge(int *arr, int start, int mid, int end)
{
    int i = start;
    int j = mid;
    int k = start;
    
    int tmpSize = end + 1;

    int* tmpArr = new int[tmpSize]();

    int inv_count = 0;

    while (i <= mid - 1 && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            tmpArr[k++] = arr[i++];
        }
        else
        {
            tmpArr[k++] = arr[j++];

            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1)
        tmpArr[k++] = arr[i++];

    while (j <= end)
        tmpArr[k++] = arr[j++];

    for (i = start; i <= end; i++)
        arr[i] = tmpArr[i];

    return inv_count;
}

int MergeSort(int *arr, int start, int end)
{
    int inv_count = 0;

    if (start < end)
    {
        int mid = start + (end - start) / 2;

        inv_count = MergeSort(arr, start, mid);
        inv_count += MergeSort(arr, mid + 1, end);

        inv_count += Merge(arr, start, mid + 1, end);
    }

    return inv_count;
}

int main()
{
    std::cout << "Enter the size of tha array \n";

    int size;

    cin >> size;

    cout << "Enter the array \n";

    int* arr = new int[size]();

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    int count = MergeSort(arr, 0, size - 1);

    cout << "Number of inversions: " << count;

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
