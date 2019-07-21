// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void swap(int& a, int& b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

void BubbleSort(int *a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int smallest = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

void Merge(int arr[], int start, int mid, int end);
void MergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);

        Merge(arr, start, mid, end);
    }
}

void Merge(int arr[], int start, int mid, int end)
{
    int nSizeLeft = mid - start + 1;
    int nSizeRight = end - mid;

    int* leftSubArr = new int[nSizeLeft];
    int* rightSubArr = new int[nSizeRight];

    int i = 0;
    int j = 0;
    int k = start;

    for (i = 0; i < nSizeLeft; ++i)
    {
        leftSubArr[i] = arr[start + i];
    }

    for (j = 0; j < nSizeRight; ++j)
    {
        rightSubArr[j] = arr[j + mid + 1];
    }

    i = 0;
    j = 0;

    while (i < nSizeLeft && j < nSizeRight)
    {
        if (leftSubArr[i] <= rightSubArr[j])
        {
            arr[k] = leftSubArr[i];
            i++;
        }
        else
        {
            arr[k] = rightSubArr[j];
            j++;
        }
        k++;
    }

    while (i < nSizeLeft)
    {
        arr[k] = leftSubArr[i];
        k++;
        i++;
    }

    while (j < nSizeRight)
    {
        arr[k] = rightSubArr[j];
        k++;
        j++;
    }

    delete[] leftSubArr;
    delete[] rightSubArr;
    leftSubArr = nullptr;
    rightSubArr = nullptr;
}

int main()
{
    int arr[8] = { 2, 4, 1, 6, 8, 5, 3, 7 };

    MergeSort(arr, 0, 7);

    for (int i = 0; i < 8; ++i)
    {
        std::cout << arr[i] << " ";
    }

    char c = getchar();
}
