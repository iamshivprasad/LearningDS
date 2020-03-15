// HackerrankMinTimeRequired.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

//long minTime(vector<long> machines, long goal) 
//{
//    sort(machines.begin(), machines.end());
//    long lower = (long) (goal / machines.size() * machines[0]);
//    long upper = (long)(goal / machines.size() * machines[machines.size()-1]);
//
//    long days = 0;
//    while (lower < upper)
//    {
//        days = (lower + upper) / 2;
//
//        int temp = 0;
//        for (auto m : machines)
//        {
//            temp += days / m;
//        }
//
//        if (temp >= goal)
//        {
//            upper = days;
//        }
//        else
//        {
//            lower = days;
//        }
//    }
//
//    return (long)lower;
//}

long minTimeRequired(vector<long> machines, long goal)
{
    sort(machines.begin(), machines.end());

    long fast = machines[0];
    long slow = machines[machines.size() - 1];

    long lower_bound = ceil((double)goal / ((double)machines.size() / fast));
    long upper_bound = ceil((double)goal / ((double)machines.size() / slow));

    long num_days = 0;
    while (lower_bound < upper_bound)
    {
        long mid = (lower_bound + upper_bound) / 2 , item = 0;
        for (int i = 0; i < machines.size(); i++)
            item += (mid / machines[i]);
        if (item >= goal)
            upper_bound = mid;
        else
            lower_bound = mid + 1;
    }

    return (long)lower_bound;
}

int main()
{
    std::cout << "Enter number of machines and target production: \n";

    long size, goal;
    cin >> size >> goal;

    vector<long> machines(size);

    for (int i = 0; i < size; ++i)
    {
        cin >> machines[i];
    }

    cout << minTimeRequired(machines, goal);

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
