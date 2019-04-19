
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the rustMurdered function below.
 */

enum class Color{
    WHITE,
    BLACK,
    GRAY
};

vector<int> BFS(int source, vector<pair<Color, vector<int>>> adjList) {
  vector<int> distances(adjList.size(), -1);
  queue<int> Q;
  set<int> white;
  set<int> unreachable;
  distances[source-1] = 0;
  adjList[source-1].first = Color::GRAY;
  Q.push(source - 1);
  for (size_t i = 0; i < adjList.size(); i++) {
    if (source - 1 != i) {
      white.insert(i);
    }
  }
  while (!Q.empty()) {
    auto nd = Q.front();
    Q.pop();
    for (size_t i = 0; i < adjList[nd].second.size(); i++) {
      if (adjList[adjList[nd].second[i]].first == Color::WHITE) {
        white.erase(adjList[nd].second[i]); // remove all reachable vertex
        unreachable.insert(adjList[nd].second[i]); // call them unreachble
        }
    }
    for (const auto &n : white) {
      adjList[n].first = Color::GRAY;
      distances[n] = distances[nd]+1;
      Q.push(n);
    }
    adjList[nd].first = Color::BLACK;
    white = unreachable;
    unreachable.clear();
  }
  distances.erase(distances.begin()+source-1);
  return distances;
}

vector<int> rustMurdered(int s, int n, vector<vector<int>> roads) {
  vector<pair<Color, vector<int>>> adjList(
      n, pair<Color, vector<int>>(Color::WHITE, vector<int>()));
  for (size_t i = 0; i < roads.size(); i++) {
    adjList[roads[i][0] - 1].second.push_back(roads[i][1] - 1);
    adjList[roads[i][1] - 1].second.push_back(roads[i][0] - 1);
    }
    return BFS(s, adjList);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> roads(m);
        for (int roads_row_itr = 0; roads_row_itr < m; roads_row_itr++) {
            roads[roads_row_itr].resize(2);

            for (int roads_column_itr = 0; roads_column_itr < 2; roads_column_itr++) {
                cin >> roads[roads_row_itr][roads_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = rustMurdered(s, n, roads);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
