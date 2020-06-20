#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) 
{
    vector<int> near(n, -1);
    vector<vector<int>> t(n);

    int minEdge = INT_MAX;
    int i = 0;
    int j = 0;
    for (auto& e : edges)
    {
        if (minEdge < e[2])
        {
            i = e[0];
            j = e[1];
            minEdge = e[2];
        }
    }

    t[0][0] = i;
    t[1][0] = j;

}

int main()
{

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

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
