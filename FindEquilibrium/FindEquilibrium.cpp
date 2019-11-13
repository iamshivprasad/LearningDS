// FindEquilibrium.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using  namespace std;

int main()
{
    std::cout << "Enter the size of the array";
    
    int size;
    cin >> size;

    cout << "Enter the array elements: ";

    int* arr = new int[size]();

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    // Find total sum

    int sum = 0;
    int leftSum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    int idx = 0;
    for (; idx < size; ++idx)
    {
        sum -= arr[idx];

        if (sum == leftSum)
            break;

        leftSum += arr[idx];
    }

    cout << "Equilibrium at " << idx;

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
