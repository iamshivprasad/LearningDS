// SherlockAndAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string s)
{
	string ss;
	int count = 0;
	vector<string> subStrings;
	for (int i = 0; i < s.size(); i++)
	{
		ss = "";
		for (int j = i; j < s.size(); j++)
		{
			subStrings.push_back(ss.append(1, s[j]));
		}
	}

	for (auto& subString : subStrings)
	{
		sort(subString.begin(), subString.end());
	}

	for (int k = 0; k < subStrings.size(); ++k)
	{
		for (int l = k + 1; l < subStrings.size(); ++l)
		{
			if (subStrings[k] == subStrings[l])
			{
				++count;
			}
		}
	}

	return count;
}


int main()
{
    std::cout << "Enter the string: \n";

	string input;
	cin >> input;

	cout << sherlockAndAnagrams(input);



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
