// CustomSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//int moves(vector<int> arr)
//{
//    int c = 0;
//    for (int i = 0; i < arr.size() / 2; ++i)
//    {
//        if (arr[i] % 2 != 0)
//        {
//            for (int j = arr.size() / 2; j < arr.size(); ++j)
//            {
//                if (arr[j] % 2 == 0)
//                {
//                    int t = arr[i];
//                    arr[i] = arr[j];
//                    arr[j] = t;
//                    ++c;
//                    break;
//                }
//            }
//        }
//    }
//
//    return c;
//}

//int countPairs(vector<int> numbers, int k) 
//{
//    unordered_set<int> s(numbers.begin(), numbers.end());
//
//    int cnt = 0;
//
//    for (auto c : s)
//    {
//        if (s.count(c + k))
//            ++cnt;
//    }
//
//    return cnt;
//}

string rollTheString(string s, vector<int> roll)
{
    int size = roll.size();
    vector<int> table(size + 1);
    string charset = "abcdefghijklmnopqrstuvwxyz";

    fill(table.begin(), table.end(), 0);

    for (int i = 0; i < size; ++i)
    {
        table[0] += 1;
        table[roll[i]] -= 1;
    }

    for (int i = 1; i < size; ++i)
        table[i] += table[i - 1];


    for (int i = 0; i < size; ++i)
    {
        int a = table[i] % 26;
        int b = s[i] - 97;
        s[i] = charset[(a + b) % 26];
    }


    return s;
}

int main()
{
    std::cout << "Enter!\n";

    string s;
    int size;
    cin >> s >> size;

    //int size, k;
    //cin >> size >> k;

    vector<int> v(size);
    for (int i = 0; i < size; ++i)
    {
        cin >> v[i];
    }

    cout << rollTheString(s, v);
    //cout << countPairs(v, k) << endl;
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
