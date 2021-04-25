// LCLongestSubStringWithoutRepeating.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    
    if (s.empty())
        return 0;

    if (s.length() == 1)
        return 1;

    int max_len = INT_MIN;

    // example: au
    int start = -1;
    unordered_map<char, int> charIndex;

    for (int i = 0; i < s.size(); ++i)
    {
        if (charIndex.count(s[i]))
        {
            // examples
            // abba, ccd, cdd, abcae
            start = max(start, charIndex[s[i]]);
        }

        charIndex[s[i]] = i;
        max_len = max(i - start, max_len);
    }

    return max_len;

}

int main()
{
    std::cout << "Enter the string: " << endl;

    string str;

    cin >> str;

    cout << lengthOfLongestSubstring(str);
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
