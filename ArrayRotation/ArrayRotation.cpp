// ArrayRotation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void rotateRight(int* arr, int size, int rotate, int*& result)
{
    result = new int[size];
    for (int i = 0; i < size; ++i)
    {
        result[(i + rotate) % size] = arr[i];
    }
}

// Rotating to the left by n is the same as rotating to the right by length-n.
void rotateLeft(int* arr, int size, int rotate, int*& result)
{
    result = new int[size];
    for (int i = 0; i < size; ++i)
    {
        result[(i + (size - rotate)) % size] = arr[i];
    }
}

int main()
{
    int arr[] = { 3,4,5,6,7,8 };
    int* result = nullptr;
    
    rotateRight(arr, 6, 2, result);

    for (int i = 0; i < 6; ++i)
    {
        std::cout << result[i] << " ";
    }

    delete[] result;
    result = nullptr;

    rotateLeft(arr, 6, 2, result);
    for (int i = 0; i < 6; ++i)
    {
        std::cout << result[i] << " ";
    }
    delete[] result;
    result = nullptr;
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