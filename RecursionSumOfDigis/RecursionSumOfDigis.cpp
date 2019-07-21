// RecursionSumOfDigis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//int Sum(int n, int sum)
//{
//    if (n == 0)
//    {
//        return sum;
//    }
//    sum += n % 10;;
//
//    return Sum(n/10, sum);
//}

int Sum(int n)
{
    if (n < 10)
    {
        return n;
    }
    return n % 10 + Sum(n / 10);
}


int main()
{
    cout << "Enter the number:";

    int n;
    cin >> n;

    int sum = 0;
    cout << Sum(n);

    int c = getchar();
}