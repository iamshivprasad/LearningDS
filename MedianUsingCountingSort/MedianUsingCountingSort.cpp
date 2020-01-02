// MedianUsingCountingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


float getMedian(vector<int> countArr, int size)
{
	float med = 0;
	if (size % 2 == 0)
	{
		int count = 0;
		int first = 0;
		int second = 0;
		for (int i = 0; i < countArr.size(); ++i)
		{
			count += countArr[i];

			if (count == size / 2 && first == 0)
				first = i;
			else if (count > size / 2)
			{
				if (first == 0)
					first = i;

				second = i;
				break;
			}
		}

		med = ((float)first + (float)second) / 2.0;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < countArr.size(); ++i)
		{
			count += countArr[i];

			if (count > size / 2)
			{
				med = i;
				break;
			}
		}
	}

	return med;
}


int main()
{
    std::cout << "Enter the size and elements\n";

	int size;
	
	cin >> size;

	vector<int> arr(size);

	for(int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}

	cout << getMedian(arr, size);

	return 0;
}

