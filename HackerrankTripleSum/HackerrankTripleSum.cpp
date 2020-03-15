// HackerrankTripleSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long triplets(vector<int> a, vector<int> b, vector<int> c) 
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long count = 0;
    int ai = 0;
    int bi = 0;
    int ci = 0;

    while (bi < b.size())
    {
        while (ai < a.size() && a[ai] <= b[bi])
            ++ai;
        while (ci < c.size() && c[ci] <= b[bi])
            ++ci;

        // Casting to long as the product can result in a big number
        count += (long)ai * ci;

        ++bi;
    }

    return count;
}


int main()
{
    std::cout << "Enter the sizes:\n";

    int lena, lenb, lenc;

    cin >> lena >> lenb >> lenc;

    vector<int> a(lena);
    vector<int> b(lenb);
    vector<int> c(lenc);

    for (int i = 0; i < lena; ++i)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < lenb; ++i)
    {
        cin >> b[i];
    }

    for (int i = 0; i < lenc; ++i)
    {
        cin >> c[i];
    }

    cout << triplets(a, b, c);
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
