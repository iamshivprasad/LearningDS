// HackerrankMarkAndToys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumToys(vector<int> prices, int k)
{
	sort(prices.begin(), prices.end());

	int i = 0;
	int sumTillNow = prices[i];

	while (sumTillNow <= k)
	{
		++i;
		sumTillNow += prices[i];
	}

	//while (sumTillNow + prices[i++] <= k)
	//	sumTillNow = sumTillNow + prices[i++];

	return i;
}

int main()
{
    std::cout << "Enter size, k and array: \n";

	int size = 0, k = 0;
	cin >> size >> k;

	vector<int> arr(size);

	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}

	cout << maximumToys(arr, k);

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
