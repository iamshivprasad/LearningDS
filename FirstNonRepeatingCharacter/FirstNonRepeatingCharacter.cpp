// FirstNonRepeatingCharacter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void FindFirstNonRepeatingChar(string str)
{
    pair<int, int> count[256];

    for (size_t i = 0; i < str.length(); i++)
    {
        count[str[i]].first++;
        count[str[i]].second = i;
    }

    int res = INT_MAX;
    for (size_t i = 0; i < 256; i++)
    {
        if (count[i].first == 1)
        {
            res = std::min(res, count[i].second);
        }
    }

    if (res == INT_MAX)
    {
        cout << "All characters are repeating" << endl;
    }
    else
    {
        cout << "First non repeating char: " << str[res] << endl;
    }

}

int main()
{
    std::cout << "Enter the string" << endl;
    
    string inputStr;
    cin >> inputStr;

    FindFirstNonRepeatingChar(inputStr);

    return 0;
}
