//The Conversion To One
//====================== =
//You are given a number N.You need to convert it to 1 in minimum number of operations.
//
//The operations allowed are as follows :
//
//If N is even then divide the number by 2.
//If N is odd then you can either add 1 to it or subtract 1 from it.
//Using the above operations, find the minimum number of operations require to convert N to 1.
//
//Input :
//    The first line of input contains T denoting the number of testcases.T testcases follow.Each testcase contains 1 line of input containing N.
//
//    Output :
//    For each testcase, in a new line, print the minimum number of steps required.
//
//    Constraints :
//    1 <= T <= 100
//    1 <= N <= 107
//
//    Examples :
//    Input :
//    4
//    1
//    2
//    3
//    4
//    Output :
//    0
//    1
//    2
//    2
//
//    Explanation :
//    Testcase1 : 1 can be converted into 1 in 0 steps.
//    Testcase2 : 2 can be converted into 1 in 1 step : 2 - 1


#include <iostream>
#include <algorithm>

using namespace std;

//int FindSteps(int n, int steps)
//{
//    if (n == 1)
//    {
//        return steps;
//    }
//    else if (n % 2 == 0)
//    {
//        return FindSteps(n / 2, steps + 1);
//    }
//
//    return FindSteps(n - 1, steps + 1);
//}

int FindStepsEx(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + FindStepsEx(n / 2);
    }

    return 1 + min(FindStepsEx(n - 1), FindStepsEx(n + 1));

}

int main()
{
    std::cout << "Enter the number: ";

    int n;
    cin >> n;

    cout << "Steps: " << FindStepsEx(n);

    char c = getchar();
}