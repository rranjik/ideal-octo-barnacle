
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

long long int
DFS(int source, vector<tuple<bool, int, vector<int>, long long int>> &adjList) {
  get<0>(adjList[source]) = true;
  for (size_t i = 0; i < get<2>(adjList[source]).size(); i++) {
    if (!get<0>(adjList[get<2>(adjList[source])[i]])) {
      get<3>(adjList[source]) += DFS(get<2>(adjList[source])[i], adjList);
    }
  }
  get<3>(adjList[source]) += get<1>(adjList[source]);
  return get<3>(adjList[source]);
    
}

long long int
minCut(vector<tuple<bool, int, vector<int>, long long int>> &adjList) {
  auto total = get<3>(adjList[0]);
  long long int res = numeric_limits<long long int>::max();
  for (size_t i = 0; i < adjList.size(); i++) {
    res = min(res, abs((2 * get<3>(adjList[i])) - total));
  }
  return res;
}

  int cutTheTree(vector<int> data, vector<vector<int>> edges) {
  auto V = data.size();
  vector<tuple<bool, int, vector<int>, long long int>> adjList(V);
  long long int res = 0;
  for (size_t i = 0; i < data.size(); i++) {
    adjList[i] = make_tuple(false, data[i], vector<int>(), 0);
  }
  for (size_t i = 0; i < edges.size(); i++) {
    get<2>(adjList[edges[i][0] - 1]).push_back(edges[i][1] - 1);
    get<2>(adjList[edges[i][1] - 1]).push_back(edges[i][0] - 1);
  }
  get<3>(adjList[0]) = DFS(0, adjList);
  cout<<"total is: "<<get<3>(adjList[0])<<endl;
    for(size_t i = 0; i<adjList.size(); i++){
      cout << i <<" sum: " << get<3>(adjList[i]) << " -> ";
      for (size_t j = 0; j < get<2>(adjList[i]).size(); j++) {
        cout << get<2>(adjList[i])[j] << " -> ";
        }
        cout<<endl;
    }
    res = minCut(adjList);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
