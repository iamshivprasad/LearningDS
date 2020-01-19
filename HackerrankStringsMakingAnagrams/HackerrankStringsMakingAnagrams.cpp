// HackerrankStringsMakingAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

	unordered_map<char, int> hashTable;

	for (auto var : a)
	{
		hashTable[var]++;
	}

	for (auto var : b)
	{
		hashTable[var]--;
	}

	int count = 0;
	for (auto val : hashTable)
	{
		if (val.first != 0)
		{
			count += abs(val.second);
		}
	}

	return count;
}


int main()
{
	string a, b;

	cin >> a >> b;

    std::cout << makeAnagram(a,b);

	return 0;
}
