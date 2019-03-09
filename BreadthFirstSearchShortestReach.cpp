
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<pair<bool, vector<int>>> adjList(n);
    vector<int> distances(n, -1);
    vector<int> res;
    for(int i = 0; i<n; i++){
        vector<int> empty = vector<int>();
        pair<bool, vector<int>> p = make_pair<bool, vector<int>>(bool(false), vector<int>(vector<int>()));
        adjList[i] = p;
    }
    for(const auto& e : edges){
        adjList[e[0]-1].second.push_back(e[1]-1);
        adjList[e[1]-1].second.push_back(e[0]-1);
    }
    distances[s-1]=0;
    queue<int> Q;
    Q.push(s-1);
    while(!Q.empty()){
        int nd = Q.front();
        //cout<<nd<<" was popped"<<std::endl;
        Q.pop();
        for(const auto& node : adjList[nd].second){
            if(!adjList[node].first){
                Q.push(node);
                adjList[node].first = true;
                distances[node] = distances[nd]+1;
            }
        }
        adjList[nd].first=true;
    }
    for(int i = 0; i< n; i++){
        if(s-1!=i)
        res.push_back((distances[i]<0)?-1:distances[i]*6);
            //cout<< ((distances[i]<0)?"-1":(to_string(distances[i]*6).c_str()))<<" ";
    }
    cout<<"tester start"<<endl;
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    for(const auto& t : test){
        cout<<t<<" ";
    }
    cout<<endl;
    test.pop_back();
    test.pop_back();
        for(const auto& t : test){
        cout<<t<<" ";
    }
    cout<<"tester start"<<endl;
    for(int i = 0; i< n; i++){
        cout<<i<<" -> ";
        for(const auto& n : adjList[i].second){
            cout<< n << " ";
        }
        cout<<endl;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
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
