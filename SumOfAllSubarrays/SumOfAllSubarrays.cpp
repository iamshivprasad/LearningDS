// SumOfAllSubarrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://web.stanford.edu/class/cs9/sample_probs/SubarraySums.pdf

/*
There's a third route you can take that runs in time O(n) but requires a bit of math. The
basic idea behind the approach is to compute the sum, but not in the order intended. For
example, take a look at the array [1, 2, 3, 4]. The subarrays are
[1]  [2]  [3]  [4]
[1, 2]   [2, 3]   [3, 4]
[1, 2, 3]   [2, 3, 4]
[1, 2, 3, 4]
Notice how many copies of each element there are. There are four 1's, six 2's, six 3's, and
four 4's. If we could efficiently compute how many copies of each element there are across
all the different subarrays, we could directly compute the sum by multiply each element
in the array by the number of times it appears across all the subarrays and then adding
them up.
You can find a bunch of interesting patterns with how many times each number shows
up. Here's one useful one. We can count the number of subarrays that overlap a particular element at index i by counting those subarrays and focusing on the index at which
those subarrays start. The first element of the array will appear in n different subarrays
– each of them starts at the first position. The second element of the array will appear in
n­1 subarrays that begin at its position, plus  n­1 subarrays from the previous position
(there are n total intervals, of which one has length one and therefore won't reach the second element). The third element of the array will appear in n­2 subarrays that begin in
its position, plus n­2 subarrays beginning at the first element (all n arrays, minus the one
of length two and the one of length one) and n­2 subarrays beginning at the second element (all n­1 of them except for the one of length one). More generally, the ith element
will open n – i new intervals (one for each length stretching out to the end) and, for each
preceding element, will overlap n – i of the intervals starting there. This means that the
total number of intervals overlapping element i is given by
(n – i)i + (n – i) = (n – i)(i + 1)
*/

#include <iostream>

using namespace std;

long int SubArraySum(int arr[], int n)
{
	long int result = 0;

	// computing sum of subarray using formula 
	for (int i = 0; i < n; i++)
		result += (arr[i] * (i + 1) * (n - i));

	// return all subarray sum 
	return result;
}

int main()
{
	int arr[] = { 1, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Sum of SubArray : "
		<< SubArraySum(arr, n) << endl;
	return 0;
}

