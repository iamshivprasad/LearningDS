// HackerrankSpecialStringAgain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long substrCount(int n, string s) 
{
    vector<pair<char, int>> countArray;
    int i = 0;
    int j = 0;
    for (i = 0; i < n; ++i)
    {
        for (j = i+1; j < n; ++j)
        {
            if (s[i] == s[j])
                continue;
            else
                break;
        }

        countArray.push_back(make_pair(s[i], j-i));
        i = j - 1;
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        count += countArray[i].second * (countArray[i].second + 1) / 2;
    }

    for (int i = 1; i < countArray.size()-1; ++i)
    {
        if (countArray[i].second == 1 && countArray[i - 1].first == countArray[i + 1].first)
        {
            count += min(countArray[i - 1].second, countArray[i + 1].second);
        }
    }

    return count;
}

int main()
{
    std::cout << "Enter the string: \n";
    string input;
    cin >> input;

    cout << substrCount(input.size(), input);
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
