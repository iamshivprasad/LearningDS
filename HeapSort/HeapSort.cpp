// HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void heapify(int arr[], int i, int n)
{
	int index;

	int leftChild;
	int rightChild;

	while (i < n)
	{
		index = i;

		leftChild = 2 * i + 1;
		rightChild = leftChild + 1;

		if (leftChild < n && arr[leftChild] > arr[index])
			index = leftChild;

		if (rightChild < n && arr[rightChild] > arr[index])
			index = rightChild;

		if (index == i)
			return;

		std::swap(arr[i], arr[index]);

		i = index;
	}

}

void buildHeap(int arr[], int n)
{
	int i = n / 2 - 1;

	while (i >= 0)
	{
		heapify(arr, i, n);
		i--;
	}
}

void heapSort(int arr[], int n)
{
	buildHeap(arr, n);

	for (int i = n - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, 0, i);
	}
}

int main()
{
	int arr[] = { 10, 200, 2, 40, 15 };

	heapSort(arr, 5);


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
