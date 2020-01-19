// HackerrankSherlockandtheValidString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

string IsValid(string str)
{
	vector<int> table(26);

	for (int i = 0; i < str.size(); ++i)
		table[str[i] - 'a']++;

	sort(table.begin(), table.end());

	int smallestIdx = 0;
	while (table[smallestIdx] == 0)
		++smallestIdx;

	int min = table[smallestIdx];
	int max = table[25];

	string ret = "NO";
	if (min == max)
		ret = "YES";
	else
	{
		// two valid conditons
		// #1 - 2 2 2 2 2 3
			// 2 2 2 2 2 3 3 is not allowed. To handle this, max > table[24]
		// #2 - 1 2 2 2 2 2
		if (max - min == 1 && max > table[24] || min == 1 && table[smallestIdx+1] == max)
		{
			ret = "YES";
		}
	}

	return ret;
}

int main()
{
    std::cout << "Enter the string\n";

	string str;
	cin >> str;

	cout << IsValid(str);

	return 0;
}
