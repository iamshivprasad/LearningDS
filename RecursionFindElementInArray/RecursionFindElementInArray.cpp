// RecursionFindElementInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Given an unsorted array of N elementsand an element X.The task is to write a recursive function to check whether the element X is present in the given array or not.
//
//Example:
//array[] = { 1, 2, 3, 4, 5 }
//X = 3.
//
//The function should return True, as 3 is
//present in the array.

bool SearchKey(int* array, int index, int key)
{
    if (index >= 5)
    {
        return false;
    }
    else if (array[index] == key)
    {
        return true;
    }
    else
        return SearchKey(array, index + 1, key);
}

int main()
{
    int array[5] = {};

    std::cout << "Enter 5 elements:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cin >> array[i];
    }

    int nKey;
    std::cout << "Enter the element to search:" << std::endl;
    std::cin >> nKey;

    if (SearchKey(array, 0, nKey))
    {
        std::cout << "Found!";
    }
    else
    {
        std::cout << "Not Found!";
    }

    return 0;
}
