// CCI_StringCompression.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

string compress(const string& in)
{
    unordered_map<char, int> table;

    int i = 0;
    stringstream ss;
    while(i < in.size() - 1)
    {
        int start = i;

        while (in[i] == in[i + 1])
            ++i;

        ss << (i-start) + 1 << in[i];

        i++;
    }

    return in.size() <= ss.str().size() ? in : ss.str();
}

int main()
{
    std::cout << "Enter the string\n";

    string str;
    cin >> str;

    cout << compress(str);
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
