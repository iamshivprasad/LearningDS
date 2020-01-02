// HackerrankCountTriplets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long countTriplets(vector<long> arr, long r) {

	unordered_map<long, long> m2, m3;
	long count = 0;
	for (auto val : arr)
	{
		if (m3.count(val))
			count += m3[val];

		if (m2.count(val))
			m3[val * r] += m2[val];

		m2[val * r]++;
	}

	return count;
}


int main()
{
	long n, r;
	cin >> n >> r;

	vector<long> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << countTriplets(arr, r);
	//map<int, long> mp2, mp3;
	////mp2 to hold count of needed values after this one to complete 
	////2nd part of triplet
	////mp3 to hold count of needed values to complete triplet

	//int val;
	//long long res = 0;
	//while (n--)
	//{
	//	cin >> val;
	//	if (mp3.count(val))		//This value completes mp3[val] triplets
	//		res += mp3[val];
	//	if (mp2.count(val))		//This value is valid as 2° part of mp2[val] triplets
	//		mp3[val * r] += mp2[val];
	//	mp2[val * r]++;			//"Push-up" this value as possible triplet start
	//}

	//cout << res << endl;

	return 0;

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
