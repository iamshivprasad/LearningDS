// QuickSelect.cpp : This file contains the 'main' function. Program execution begins and ends there.
// To find kth smallest element


#include <iostream>

using namespace std;

int partition(int* arr, int start, int end)
{
	int pivot = arr[end];
	int i = start - 1;

	for (int j = start; j < end; ++j)
	{
		if (arr[j] < pivot)
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
	}

	std::swap(arr[i + 1], arr[end]);

	return i + 1;
}


int QuickSelect(int* arr, int start, int end, int k)
{
	while (start <= end)
	{
		int partIdx = partition(arr, start, end);

		if (partIdx == k - 1)
		{
			return arr[partIdx];
		}

		if (partIdx > k - 1)
		{
			end = partIdx - 1;
		}
		else if (partIdx < k - 1)
		{
			start = partIdx + 1;
		}

	}
}

int main()
{
    std::cout << "Enter the size of array and k\n";
	
	int size, k;
	cin >> size >> k;


	cout << "Enter the array: \n";

	int* arr = new int[size]();
	
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}

	cout << "Result: " << QuickSelect(arr, 0, size - 1, k);

	cin.get();

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
