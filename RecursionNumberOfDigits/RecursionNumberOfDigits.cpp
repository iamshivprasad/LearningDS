// RecursionNumberOfDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int countDigits(int n)
{
    if (n < 10)
    {
        return 1;
    }

    return 1 + countDigits(n / 10);
}

int main()
{
    cout << "Number of test cases";
    int testCases = 0;
    cin >> testCases;

    cout << "Enter the number: ";

    int n;
    cin >> n;

    cout << "Number of digits: " << countDigits(n);
}

