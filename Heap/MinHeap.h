#pragma once
class MinHeap
{
private:
    int* heapElements;
    int capacity;
    int heap_size;

public:
    MinHeap(int size) : capacity(size), heap_size(0)
    {
        heapElements = new int[size];
    }

    void insertKey(int n);
};

