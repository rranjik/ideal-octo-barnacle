
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<vector<pair<int, int>>> buildAdjList(const vector<vector<int>>& roads){
    vector<vector<pair<int, int>>> adjList(roads.size()+2);
    for(const auto& road : roads){
        adjList[road[0]-1].push_back(pair<int, int>(road[2], road[1]-1));
        adjList[road[1]-1].push_back(pair<int, int>(road[2], road[0]-1));
    }
    return adjList;
}

bool DFS(int source, const vector<vector<pair<int, int>>>& adjList, vector<bool>& visited, vector<bool>& include, const vector<int> cities){
    visited[source] = true;
    if(find(cities.begin(), cities.end(), source+1)!=cities.end()){
        include[source] = true;
    }
    bool childIncluded = false; 
    for(const auto& child : adjList[source]){
        if(!visited[child.second]){
            childIncluded |= DFS(child.second, adjList, visited, include, cities);
        }
    }
    if(childIncluded)
        include[source] = true;
    return include[source];
}

vector<int> nodesToInclude(vector<int>& excludes, const vector<int>& cities, const vector<vector<pair<int, int>>>& adjList){
   vector<int> res;
   vector<bool> visited(adjList.size(), false);
   vector<bool> include(adjList.size(), false);
   DFS(cities[0]-1, adjList, visited, include, cities); 
   for(size_t i = 0; i< include.size(); i++){
       if(include[i]){
           res.push_back(i);
       }
       else excludes.push_back(i);
   }
   return res;
}

void DFSD(vector<int>& distances, const int src, vector<bool>& visited, const vector<vector<pair<int, int>>>& adjList, int dist){
    if(!visited[src]){
        visited[src] = true;
        distances[src]+=dist;
        for(const auto& child : adjList[src]){
           DFSD(distances, child.second, visited, adjList, distances[src]+child.first);
        }
    }
}

vector<vector<pair<int, int>>> trimAdjList(vector<vector<pair<int, int>>> adjList, const vector<int>& includes,
vector<int>& excludes, const vector<vector<int>>& includemap){
    auto excluded_so_far = 0;
    for(const auto& i : excludes){
        adjList.erase(adjList.begin()+i-excluded_so_far);
        excluded_so_far++;
    }
    // cout<<"herebefore"<<endl;
    // for(size_t i = 0; i<adjList.size(); i++){
    //     cout<<i<<" -> ";
    //     for(size_t j = 0; j<adjList[i].size(); j++){
    //         cout<<adjList[i][j].second<<" -> ";
    //     }
    //     cout<<endl;
    // }
    //cout<<"here"<<endl;
    for(auto& node : adjList){
           node.erase(remove_if(node.begin(), node.end(), 
           [&](pair<int, int> p)
           {return find(includes.begin(), includes.end(), p.second)==includes.end();}),
           node.end()); 
           for(auto& n : node){
               n.second = includemap[n.second][0];
           }
    }
    // for(size_t i = 0; i<adjList.size(); i++){
    //     cout<<i<<" -> ";
    //     for(size_t j = 0; j<adjList[i].size(); j++){
    //         cout<<adjList[i][j].second<<" -> ";
    //     }
    //     cout<<endl;
    // }
    return adjList;
}

/*
 * Complete the jeanisRoute function below.
 */
int jeanisRoute(vector<int> k, vector<vector<int>> roads) {
    /*
     * Write your code here.
     */ 
    //  for(const auto& c : k){
    //      cout<<c<<endl;
    //  }
     auto adjList = buildAdjList(roads);
    //  for(size_t i = 0; i<adjList.size(); i++){
    //      cout<<i<<" -> ";
    //      for(size_t j = 0; j<adjList[i].size(); j++){
    //          cout<<adjList[i][j].second<<" wieghs: "<<adjList[i][j].first<<" -> ";
    //      }
    //      cout<<endl;
    //  }
     vector<int> excludes;
     auto include = nodesToInclude(excludes, k, adjList);
     auto includemap = vector<vector<int>> (roads.size()+1, vector<int>(1, 0));
     int number_of_included_nodes = 0;
     for(size_t k = 0; k<include.size(); k++){
         includemap[include[k]][0]=number_of_included_nodes; 
         //cout<<include[k]<<endl;
         number_of_included_nodes++;
     }
    //cout<<"excludes"<<endl;
    // for(const auto& i: excludes){
    //      cout<<i<<endl;
    //  }
    //  for(const auto& i : include){
    //      for(size_t j = 0; i<adjList[i].size(); j++){
    //          if(find(include.begin(), include.end(), adjList[i][j])!= include.end()){
                 
    //          }
    //      }
    //  }
     auto trimedAdjList = trimAdjList(adjList, include, excludes, includemap);
    //  cout<<"after trimming"<<endl;
    //  for(size_t i = 0; i<trimedAdjList.size(); i++){
    //     cout<<i<<" -> ";
    //     for(size_t j = 0; j<trimedAdjList[i].size(); j++){
    //         cout<<trimedAdjList[i][j].second<<" wieghs: "<<trimedAdjList[i][j].first<<" -> ";
    //     }
    //     cout<<endl;
    // } 
    vector<int> distances(trimedAdjList.size(), 0);
    vector<bool> visit(trimedAdjList.size(), false);
    DFSD(distances, 0, visit, trimedAdjList,0);
    //cout<<"after dfsd"<<endl;
    int max = 0;
    int counter = 0;
    int far1 = 0;
    for(const auto& d : distances){
        //cout<<d<<endl;
        if(d>max){
            max=d;
            far1 = counter;
        }
        counter++;
    }
    distances = vector<int>(trimedAdjList.size(), 0);
    visit = vector<bool>(trimedAdjList.size(), false);
    DFSD(distances, far1, visit, trimedAdjList,0);
    int diameter = 0;
    counter = 0;
    for(const auto& d : distances){
        //cout<<d<<endl;
        if(d>diameter){
            diameter=d;
        }
        counter++;
    }
    int sum = 0;
    for(const auto& n : trimedAdjList){
        for(const auto& c : n){
            sum+=c.first;
        }
    } 
    int res = (sum-diameter);
     return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string city_temp_temp;
    getline(cin, city_temp_temp);

    vector<string> city_temp = split_string(city_temp_temp);

    vector<int> city(k);

    for (int city_itr = 0; city_itr < k; city_itr++) {
        int city_item = stoi(city_temp[city_itr]);

        city[city_itr] = city_item;
    }

    vector<vector<int>> roads(n-1);
    for (int roads_row_itr = 0; roads_row_itr < n-1; roads_row_itr++) {
        roads[roads_row_itr].resize(3);

        for (int roads_column_itr = 0; roads_column_itr < 3; roads_column_itr++) {
            cin >> roads[roads_row_itr][roads_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = jeanisRoute(city, roads);

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
