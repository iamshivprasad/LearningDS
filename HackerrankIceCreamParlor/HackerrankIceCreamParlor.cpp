// HackerrankIceCreamParlor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

void whatFlavors(vector<int> cost, int money) 
{
    multimap<int, int> table;

    for (int i = 0; i < cost.size(); ++i)
    {
        table.insert(pair<int, int>(cost[i], i + 1));
    }

    sort(cost.begin(), cost.end());

    int left = 0;
    int right = cost.size() - 1;
    int sum = 0;
    while (left < right)
    {
        sum = cost[left] + cost[right];

        if (sum > money)
        {
            right--;
        }
        else if (sum < money)
        {
            left++;
        }
        else
        {
            if (cost[left] != cost[right])
            {
                int first = table.find(cost[left])->second;
                int second = table.find(cost[right])->second;

                if (first > second)
                {
                    first = first ^ second;
                    second = first ^ second;
                    first = first ^ second;
                }

                cout << first << " " << second;

            }
            else
            {
                auto res = table.equal_range(cost[left]);

                for (auto it = res.first; it != res.second; it++) {
                    cout << it->second << " ";
                }
            }
            cout << "\n";

            break;
        }
    }
}

int main()
{
    std::cout << "Enter money, size of cost array and costs:\n";

    int money, size;
    cin >> money >> size;

    vector<int> costs(size);
    for (int i = 0; i < size; ++i)
    {
        cin >> costs[i];
    }

    whatFlavors(costs, money);
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
