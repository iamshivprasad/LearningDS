// PossibleWordsFromPhoneDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

char keyPad[9][5] = { "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

void possibleWords(int a[], int N)
{

}

int main()
{
    cout << "Enter the size of array: ";
    
    int n;
    cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    possibleWords(a, n);
}
