#pragma once
class MaxHeap
{
private:
    int* heapElements;
    int capacity;
    int heap_size;

private:
    static void heapify(int* arr, int k, int size);

public:
    MaxHeap(int size) : capacity(size), heap_size(1)
    {
        heapElements = new int[size];
    }

    void insertKey(int n);

	void deleteKey();

    static void BuildMaxHeap(int* arr, int size);
};

