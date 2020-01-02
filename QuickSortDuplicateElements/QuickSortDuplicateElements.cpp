// QuickSortDuplicateElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

void quickSort(vector<int>& arr, int lo, int hi)
{
	if (hi <= lo)
		return;

	int lt = lo;
	int gt = hi;

	int pivot = arr[lo];
	int i = lo;

	while (i <= gt)
	{
		if (arr[i] < pivot)
		{
			swap(arr[i], arr[lt]);
			++lt;
			++i;
		}
		else if (arr[i] > pivot)
		{
			swap(arr[i], arr[gt]);
			--gt;
		}
		else
		{
			++i;
		}
	}


	quickSort(arr, lo, lt - 1);
	quickSort(arr, gt + 1, hi);

}

int main()
{
    std::cout << "Enter the size: \n";
	
	int size;
	cin >> size;

	vector<int> arr(size);
	
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}

	quickSort(arr, 0, size - 1);

	
}
