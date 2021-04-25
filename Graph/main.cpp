#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <string>
#include <stack>
#include <map>
#include <list>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) 
{
    map<long, list<long>> adj;
    for (auto city : cities)
    {
        adj[city[0]].push_back(city[1]);
        adj[city[1]].push_back(city[0]);

    }


    if (c_road > c_lib || cities.size() == 0)
        return (long) ( n * c_lib );

    long cost = 0;
    long countRoad = -1;
    long countLib = 0;
    stack<long> s;
    
    bool* visited = new bool[n+1];
    for (long i = 0; i <= n; i++)
    {
        visited[i] = false;
        adj[i];
    }


    for (auto a : adj)
    {
        if (!visited[a.first])
        {
            s.push(cities[0][0]);
            ++countLib;

            while (!s.empty())
            {
                auto t = s.top();
                s.pop();

                if (!visited[t])
                {
                    visited[t] = true;
                    ++countRoad;

                    if (adj.find(t) != adj.end())
                    {
                        for (auto itr = adj[t].begin(); itr != adj[t].end(); ++itr)
                        {
                            if (!visited[*itr])
                            {
                                s.push(*itr);
                            }
                        }
                    }
                }
            }
        }
    }

    return (long)(countRoad * c_road ) + (long) (countLib * c_lib);
}

//class B
//{
//public:
//    int a;
//    void display()
//    {
//        cout << "hello";
//    }
//};

int main()
{
    //B* ptr = NULL;
    //ptr->display();

    //int q;
    //cin >> q;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //for (int q_itr = 0; q_itr < q; q_itr++) {
    //    string nmC_libC_road_temp;
    //    getline(cin, nmC_libC_road_temp);

    //    vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

    //    int n = stoi(nmC_libC_road[0]);

    //    int m = stoi(nmC_libC_road[1]);

    //    int c_lib = stoi(nmC_libC_road[2]);

    //    int c_road = stoi(nmC_libC_road[3]);

    //    vector<vector<int>> cities(m);
    //    for (int i = 0; i < m; i++) {
    //        cities[i].resize(2);

    //        for (int j = 0; j < 2; j++) {
    //            cin >> cities[i][j];
    //        }

    //        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //    }

    //    long result = roadsAndLibraries(n, c_lib, c_road, cities);

    //    cout << result << "\n";
    //}


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
