// LoadBalancing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)

    if (A.size() < 5 || A.size() > 100000)
        return false;

    int l = 1;
    int r = A.size() - 2;

    long leftSum = A[0];
    long rightSum = A[A.size() - 1];
    long midSum = 0;

    long totalSum = 0;

    for (auto i : A)
        totalSum += i;

    while (l < r)
    {
        midSum = totalSum - (leftSum + rightSum + A[l] + A[r]);

        if (midSum < leftSum || midSum < rightSum)
        {
            return false;
        }

        if (leftSum == rightSum && midSum == rightSum)
        {
            return true;
        }
        else if (leftSum > rightSum)
        {
            rightSum += A[r];
            --r;
        }
        else
        {
            leftSum += A[l];
            ++l;
        }
    }

    return false;

}
int main()
{
    cout << "Size: " << endl;
    int size;
    cin >> size;
    vector<int> arr(size);
    
    cout << "Elements: " << endl;

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    solution(arr);
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
