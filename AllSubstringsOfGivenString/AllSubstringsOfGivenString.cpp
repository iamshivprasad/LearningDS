// AllSubstringsOfGivenString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void DisplaySubstrings(string str, int start, int end, string curr)
{
	if (start == end)
		return;

	cout << curr << "\n";

	for (int i = start + 1; i < end; ++i)
	{
		curr += str[i];

		DisplaySubstrings(str, i, end, curr);

		curr = curr.erase(curr.size() - 1);
	}

	return;
}

int main()
{
    std::cout << "Enter the string\n";

	string inputString;

	cin >> inputString;

	DisplaySubstrings(inputString, -1, inputString.size(), "");

	return 0;
}

