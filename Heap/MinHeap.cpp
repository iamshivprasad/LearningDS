#include "MinHeap.h"
#include <iostream>

void MinHeap::insertKey(int n)
{
    if (heap_size == capacity)
    {
        throw "Heap overflow!!!";
    }

    heapElements[heap_size++] = n;

    int i = 0;
    while (i != 0 && heapElements[(i-1)/2] > heapElements[i])
    {
        heapElements[(i - 1) / 2] = heapElements[(i - 1) / 2] ^ heapElements[i];
        heapElements[i] = heapElements[(i - 1) / 2] ^ heapElements[i];
        heapElements[(i - 1) / 2] = heapElements[(i - 1) / 2] ^ heapElements[i];

        i = (i - 1) / 2;
    }

}