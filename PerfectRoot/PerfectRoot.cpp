//Nearest Perfect square
//======================
//You are given a number N.You need to find the perfect square that is nearest to it.If two perfect squares are at the same distance to N, then print the greater perfect square.
//
//Input:
//The first line of input contains T denoting the number of testcases.T testcases follow.Each testcase contains one line of input containing N.
//
//Output :
//    For each testcase, in a new line, print the perfect square closest to N.
//
//    Constraints :
//    1 <= T <= 100
//    1 <= N <= 1014
//
//    Examples :
//    Input :
//    3
//    1
//    56
//    100
//    Output :
//    0
//    49
//    81
//
//    Explanation :
//    Testcase1 : 0 and 4 are near to 1. 0 is nearest.
//    Testcase2 : 49 and 64 are near to 56. 49 is nearest.

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int findClosestPerfectSquare(int n)
{
    int nextPerfectSq = n + 1;
    while (true)
    {
        double sq = sqrt(nextPerfectSq);
        if ((sq - floor(sq)) == 0)
            break;
        else
            nextPerfectSq = nextPerfectSq + 1;
    }

    int prevPerfectSq = n - 1;
    while (prevPerfectSq > 0)
    {
        double sq = sqrt(prevPerfectSq);
        if ((sq - floor(sq)) == 0)
            break;
        else
            prevPerfectSq = prevPerfectSq - 1;
    }

    int diffWithNext = nextPerfectSq - n;
    int diffWithPrev = n - prevPerfectSq;

    int closestPerfectSq = 0;
    if (diffWithNext == min(diffWithNext, diffWithPrev))
    {
        closestPerfectSq = nextPerfectSq;
    }
    else
    {
        closestPerfectSq = prevPerfectSq;
    }

    return closestPerfectSq;

}

int main()
{
    cout << "Enter the number";

    int n;
    cin >> n;

    cout << "Closest perfect square: " << findClosestPerfectSquare(n);
    int t = getchar();
}

