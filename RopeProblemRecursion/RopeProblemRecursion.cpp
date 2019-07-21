// RopeProblemRecursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Problem: Given a rope of length n, and three - piece lengths a, band c.We need to find the maximum number of pieces we can make of the rope such that the length of every piece is in{ a, b, c }.
//
//    Examples :
//    Input : n = 5, a = 1, b = 2, c = 3
//    Output : 5
//    We make 5 pieces each of length 1.
//
//    Input : n = 23, a = 11, b = 9, c = 12
//    Output : 2
//    We make 2 pieces lengths 11 and 12.

#include <iostream>
#include <algorithm>

int FindMax(int n, int a, int b, int c)
{
    if (n < 0)
    {
        return -1;
    }

    if (n == 0)
    {
        return 0;
    }

    int cA = FindMax(n - a, a, b, c);
    int cB = FindMax(n - b, a, b, c);
    int cC = FindMax(n - c, a, b, c);

    int max = std::max(std::max(cA, cB), cC);

    if (max == -1)
        return -1;
    else
        return max + 1;
}

int main()
{
    std::cout << "Hello World!\n";
    int n = FindMax(34, 11, 9, 12);
}

