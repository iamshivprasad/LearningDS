// LeetCodeRemoveComments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<string> removeComments(vector<string>& source)
{
    vector<string> out;
    
    bool inBlock = false;
    string valid;

    for (auto s : source)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            string t = s.substr(i, 2);

            if (!inBlock)
            {
                if (t == "//")
                    break;
                else if (t == "/*")
                {
                    inBlock = true;
                    ++i;
                }
                else
                {
                    valid.push_back(s[i]);
                }
            }
            else if (t == "*/")
            {
                inBlock = false;
                i++;
            }

            if (!inBlock && valid.size() != 0)
            {
                out.push_back(valid);
                valid.clear();
            }
        }
    }

    return out;

}

int main()
{
    std::cout << "Hello World!\n";
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
