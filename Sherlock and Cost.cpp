#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;
  }
};

unordered_map<pair<int, int>, int, pair_hash> lookup;

int DP(const vector<int>& B, int i, int l) {
  auto coordinate = pair<int, int>((int)i, (int)l);
  if (lookup.find(coordinate) != lookup.end())
    return lookup[coordinate];
  else if (i == 0){

    lookup[coordinate] = max(abs(B[0] - l), abs(1 - l));
    return lookup[coordinate];
  }
  else {
    lookup[coordinate] =
        max(DP(B, i - 1, 1) + abs(1 - l), DP(B, i - 1, B[i]) + abs(B[i] - l));
    return lookup[coordinate];
  }
}

// Complete the cost function below.
int cost(vector<int> B) {
    return max(DP(B, B.size()-2, B[B.size()-1]), DP(B, B.size()-2, 1));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split_string(B_temp_temp);

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        int result = cost(B);
        lookup.clear();
        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
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
