// RadixSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int>& arr, int div)
{
    vector<int> countArr(10);
    vector<int> output(arr.size());
    for (int i = 0; i < arr.size(); ++i)
    {
        countArr[(arr[i] / div) % 10]++;
    }

    for (int i = 1; i < countArr.size(); ++i)
    {
        countArr[i] = countArr[i] + countArr[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i)
    {
        output[countArr[(arr[i] / div) % 10] - 1] = arr[i];
        countArr[(arr[i] / div) % 10]--;
    }

    int size = arr.size();
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr)
{
    int largest = *max_element(arr.begin(), arr.end());

    for (int i = 1; largest / i > 0; i = i * 10)
    {
        countSort(arr, i);
    }
}

int main()
{
    std::cout << "Enter size\n";
    int size;

    cin >> size;
    
    vector<int> arr;
    arr.resize(size);

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    radixSort(arr);

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }

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
