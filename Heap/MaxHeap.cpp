#include "MaxHeap.h"
#include <iostream>

void MaxHeap::insertKey(int n)
{
    if (heap_size - 1 == capacity)
    {
        throw "Heap overflow!!!";
    }

    heapElements[heap_size++] = n;

	if (heap_size > 1)
	{
		int j = heap_size - 1;
		while (heapElements[j] > heapElements[j/2] && j > 1)
		{
			std::swap(heapElements[j], heapElements[j / 2]);
			j = j / 2;
		}
	}

}

void MaxHeap::deleteKey()
{
	if (heap_size < 1)
		return;

	int deletedElement = heapElements[1];
	heapElements[1] = heapElements[heap_size - 1];
	heap_size--;


	int i = 1;
	int j = 2 * i;
	while (j < heap_size)
	{
		if (heapElements[j+1] > heapElements[j])
		{
			j++;
		}

		if (heapElements[j] > heapElements[i])
		{
			std::swap(heapElements[j], heapElements[i]);
			i = j;
			j = 2 * j;
		}
		else
			break;

	}
}

void MaxHeap::BuildMaxHeap(int* arr, int size)
{
	for (int i = (size / 2) - 1; i >= 0; --i)
	{
		heapify(arr, i, size);
	}

}

void MaxHeap::heapify(int* arr, int k, int size)
{
	int n = arr[k];

	int l = 0;
	int r = 0;
	int largest = 0;

	while (k < size)
	{
		l = 2 * k + 1;
		r = 2 * k + 2;
		largest = k;

		if (l < n && arr[l] > arr[largest])
			largest = l;
		if (r < n && arr[r] > arr[largest])
			largest = r;

		if (largest == k)
		{
			break;
		}
		else
		{
			std::swap(arr[largest], arr[k]);
			k = largest;
		}
	}
}
