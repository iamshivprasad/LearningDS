// CountAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

bool isCountZero(int count[256])
{
	for (int i = 0; i < 256; i++)
		if (count[i] != 0)
			return false;
	return true;
}

int countAnagrams(string text, string word)
{
	int N = text.length();
	int n = word.length();
	int res = 0;

	int count[256];
	memset(count, 0, 256 * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		count[word[i]]++;
	}

	for (int j = 0; j < n; ++j)
	{
		count[text[j]]--;
	}

	if (isCountZero(count))
		res++;

	for (int i = n; i < N; i++) {

		// Add last character of current 
		// window 
		count[text[i]]--;

		// Remove first character of previous 
		// window. 
		count[text[i - n]]++;

		// If count array is 0, we found an 
		// anagram. 
		if (isCountZero(count))
			res++;
	}
	return res;
}

int main()
{
    std::cout << "Enter the text and word: \n";
	string text, word;

	cin >> text >> word;

	int count = countAnagrams(text, word);
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
