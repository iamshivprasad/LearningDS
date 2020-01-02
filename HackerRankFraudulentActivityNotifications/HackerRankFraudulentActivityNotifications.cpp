#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int activityNotifications(vector<int> expenditure, int d);

vector<string> split_string(string);

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

		med = ((float)first + (float)second )/ 2.0;
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

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) 
{
	int count = 0;

	vector<int> countArr(201);
	for (int i = 0; i < d; ++i)
	{
		countArr[expenditure[i]]++;
	}

	for (int i = d; i < expenditure.size(); ++i)
	{
		float median = getMedian(countArr, d);

		if (expenditure[i] >= median * 2)
		{
			++count;
		}

		countArr[expenditure[i - d]]--;
		countArr[expenditure[i]]++;
	}
	return count;
}

int main()
{
	string nd_temp;
	getline(cin, nd_temp);

	vector<string> nd = split_string(nd_temp);

	int n = stoi(nd[0]);

	int d = stoi(nd[1]);

	string expenditure_temp_temp;
	getline(cin, expenditure_temp_temp);

	vector<string> expenditure_temp = split_string(expenditure_temp_temp);

	vector<int> expenditure(n);

	for (int i = 0; i < n; i++) {
		int expenditure_item = stoi(expenditure_temp[i]);

		expenditure[i] = expenditure_item;
	}

	int result = activityNotifications(expenditure, d);

	cout << result << "\n";


	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
		return x == y and x == ' ';
		});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
