#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>

using namespace std;

vector<string> split_string(string);

struct great
{
    template<class T>
    bool operator()(T const& a, T const& b) const { return a > b; }
};
// Complete the climbingLeaderboard function below.
//vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) 
//{
//    std::sort(scores.begin(), scores.end(), great()); 
//    auto last = std::unique(scores.begin(), scores.end());
//    scores.erase(last, scores.end());
//
//    vector<int> result;
//
//    int l = 0;
//    int r = scores.size() - 1;
//
//    for (auto a : alice)
//    {
//        if (a > scores[0])
//            result.push_back(1);
//        else if (a < scores[scores.size() - 1])
//            result.push_back(scores.size());
//        else
//        {
//            while (l <= r)
//            {
//                int mid = l + (r - l) / 2;
//                if (a == scores[mid])
//                    result.push_back(mid + 1);
//                else if (a > scores[mid])
//                {
//                    r = mid;
//                }
//                else
//                {
//                    result.push_back(mid + 2);
//                    break;
//                }
//            }
//        }
//    }
//
//    return result;
//}

vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
    // Complete this function
    int h_rank = 1;
    for (int i = scores.size() - 1; i > 0; i--) {
        if (scores[i] < scores[i - 1]) {
            h_rank++;
        }
    }
    h_rank++;
    vector<int>ranks(alice.size());
    int j = scores.size() - 1;
    for (int i = 0; i < alice.size(); i++) {
        while (alice[i] >= scores[j]) {
            if (h_rank == 1) {
                break;
            }
            if (scores[j] == scores[j - 1]) {
                j--;
            }
            else {
                j--;
                h_rank--;
            }
        }
        ranks[i] = h_rank;
    }
    return ranks;
}

int main()
{
    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";


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
