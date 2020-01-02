#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

vector<int> freqQuery(vector<vector<int>> queries) 
{
	vector<int> result;
	unordered_map<int, int> data;
	unordered_map<int, int> freq;
	//ofstream stream("o.txt");
	for (int i = 0; i < queries.size(); ++i)
	{
		switch (queries[i][0])
		{
			case 1:
				
				if (data.count(queries[i][1]) > 0)
				{
					freq[data[queries[i][1]]]--;

					if (freq[data[queries[i][1]]] <= 0)
						freq.erase(data[queries[i][1]]);
				}

				data[queries[i][1]]++;
				freq[data[queries[i][1]]]++;
				break;
			
			case 2:
				
				freq[data[queries[i][1]]]--;
				if (freq[data[queries[i][1]]] <= 0)
					freq.erase(data[queries[i][1]]);

				if (data.count(queries[i][1]) > 0)
				{
					data[queries[i][1]]--;
				}

				if (data[queries[i][1]] <= 0)
					data.erase(queries[i][1]);
				else
					freq[data[queries[i][1]]]++;
				break;

			case 3:
			{
				int res = freq.count(queries[i][1]) > 0 ? 1 : 0;
				// introduced freq map to reduce the running time
				//for (auto val : data)
				//{
				//	if (val.second == queries[i][1])
				//	{
				//		res = 1;
				//		break;
				//	}
				//}
				//stream << res << "\n";
				result.push_back(res);
			}
			break;

			default:
				break;
		}
	}

	return result;
}

int main()
{
	cout << "Enter the number of queries and queries: " << endl;

	int n;
	cin >> n;
	
	int i=0, j=0;
	int q = 0, data = 0;
	vector<vector<int>> queries(n);
	for (int i = 0; i < n; ++i)
	{
		queries[i].resize(2);
		cin >> q >> data;
		queries[i][0] = q;
		queries[i][1] = data;
	}

	//std::ifstream file("D:\\Junks\\input07.txt");
	//std::string str;
	//while (file >> q >> data)
	//{
	//	queries[i].resize(2);
	//	queries[i][0] = q;
	//	queries[i][1] = data;
	//	++i;
	//}

	vector<int> result = freqQuery(queries);

	return 0;
}
