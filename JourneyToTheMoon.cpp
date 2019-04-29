
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> DFS(int src, vector<int>& cmpnts, 
                vector<bool>& visited, const vector<vector<int>>& adjlist){
    if(!visited[src])
    {
        visited[src] = true;
        cmpnts.push_back(src);
        for(const auto& child : adjlist[src]){
            DFS(child, cmpnts, visited, adjlist);
        }
    }
    return cmpnts;
}

// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> astronaut) {
   vector<vector<int>> adjlist(n, vector<int>());
   for(const auto& p : astronaut){
       adjlist[p[0]].push_back(p[1]);
       adjlist[p[1]].push_back(p[0]);
   }
//    for(size_t i = 0; i< adjlist.size(); i++){
//        cout<<i<<"->";
//        for(size_t j = 0; j<adjlist[i].size(); j++){
//            cout<<adjlist[i][j]<<"->";
//        }
//        cout<<endl;
//    }
    vector<vector<int>> cc;
   vector<bool> visited(n, false);
   for(size_t i = 0; i<visited.size(); i++){
       if(!visited[i]){
           vector<int> cmpnts;
           DFS(i, cmpnts, visited, adjlist);
           cc.push_back(cmpnts);
       }
   }
   cout<<cc.size()<<endl;
   int ccsizesum = 0;
   for(size_t i = 0; i< cc.size(); i++){
      //cout<<i<<"->";
       ccsizesum += cc[i].size();
    //    for(size_t j = 0; j<cc[i].size(); j++){
    //        //cout<<cc[i][j]<<"->";
    //    }
    //    cout<<endl;
   }
   int res = 0;
   int cumulative = cc[0].size();
   for(size_t j = 0; j< cc.size(); j++){
      res+=(cc[j].size()*(ccsizesum-cumulative));
      if(j<cc.size()-1)
      cumulative += cc[j+1].size();
   }
   return res; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

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
