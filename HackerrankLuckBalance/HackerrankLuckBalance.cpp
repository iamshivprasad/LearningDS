// HackerrankLuckBalance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<map>
#include <set>
#include <list>

using namespace std;

int luckBalance(int k, vector<vector<int>> contests) 
{
    //map<int, set<int>> table;
    //
    //int totalSum = 0;
    //for (auto& contest : contests)
    //{
    //    table[contest[1]].insert(contest[0]);

    //    if (contest[1] == 0)
    //    {
    //        totalSum = totalSum + contest[0];
    //    }
    //}

    //if (table.find(1) != table.end())
    //{
    //    std::set<int>::reverse_iterator it = table[1].rbegin();
    //    int i = 1;
    //    while (it != table[1].rend())
    //    {
    //        if (i <= k)
    //        {
    //            totalSum += *it;
    //        }
    //        else
    //        {
    //            totalSum -= *it;
    //        }
    //        ++i;
    //        ++it;
    //    }
    //}

    map<int, list<int>> table;

    int totalSum = 0;
    for (auto& contest : contests)
    {
        table[contest[1]].push_back(contest[0]);

        if (contest[1] == 0)
        {
            totalSum = totalSum + contest[0];
        }
    }

    if (table.find(1) != table.end())
    {
        table[1].sort();
        std::list<int>::reverse_iterator it = table[1].rbegin();
        int i = 1;
        while (it != table[1].rend())
        {
            if (i <= k)
            {
                totalSum += *it;
            }
            else
            {
                totalSum -= *it;
            }
            ++i;
            ++it;
        }
    }

    return totalSum;
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    cout << result << "\n";


    return 0;
}
