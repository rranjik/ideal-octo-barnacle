#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<vector<int>> buildAdjList(const vector<vector<int>>& roads){
    vector<vector<int>> adjList(roads.size()+2);
    for(const auto& road : roads){
        adjList[road[0]-1].push_back(road[1]-1);
        adjList[road[1]-1].push_back(road[0]-1);
    }
    return adjList;
}

bool DFS(int source, const vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& include, const vector<int> cities){
    visited[source] = true;
    if(find(cities.begin(), cities.end(), source+1)!=cities.end()){
        include[source] = true;
    }
    bool childIncluded = false; 
    for(const auto& child : adjList[source]){
        if(!visited[child]){
        if(!visited[child]){
        if(!visited[child]){
            childIncluded |= DFS(child, adjList, visited, include, cities);
        }
    }
    if(childIncluded)
        include[source] = true;
    return include[source];
}

vector<int> nodesToInclude(vector<int>& excludes, const vector<int>& cities, const vector<vector<int>>& adjList){
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

vector<vector<int>> trimAdjList(vector<vector<int>> adjList, const vector<int>& includes,
vector<int>& excludes, const vector<vector<int>>& includemap){
    auto excluded_so_far = 0;
    for(const auto& i : excludes){
        adjList.erase(adjList.begin()+i-excluded_so_far);
        excluded_so_far++;
    }
    cout<<"herebefore"<<endl;
    for(size_t i = 0; i<adjList.size(); i++){
        cout<<i<<" -> ";
        for(size_t j = 0; j<adjList[i].size(); j++){
            cout<<adjList[i][j]<<" -> ";
        }
        cout<<endl;
    }
    cout<<"here"<<endl;
    for(auto& node : adjList){
           node.erase(remove_if(node.begin(), node.end(), 
           [&](int i)
           {return find(includes.begin(), includes.end(), i)==includes.end();}),
           node.end()); 
           for(auto& n : node){
               n = includemap[n][0];
           }
    }
    for(size_t i = 0; i<adjList.size(); i++){
        cout<<i<<" -> ";
        for(size_t j = 0; j<adjList[i].size(); j++){
            cout<<adjList[i][j]<<" -> ";
        }
        cout<<endl;
    }
    return adjList;
}

/*
 * Complete the jeanisRoute function below.
 */
int jeanisRoute(vector<int> k, vector<vector<int>> roads) {
    /*
     * Write your code here.
     */ 
     for(const auto& c : k){
         cout<<c<<endl;
     }
     auto adjList = buildAdjList(roads);
     for(size_t i = 0; i<adjList.size(); i++){
         cout<<i<<" -> ";
         for(size_t j = 0; j<adjList[i].size(); j++){
             cout<<adjList[i][j]<<" -> ";
         }
         cout<<endl;
     }
     vector<int> excludes;
     auto include = nodesToInclude(excludes, k, adjList);
     auto includemap = vector<vector<int>> (roads.size()+1, vector<int>(1, 0));
     int number_of_included_nodes = 0;
     for(size_t k = 0; k<include.size(); k++){
         includemap[include[k]][0]=number_of_included_nodes; 
         cout<<include[k]<<endl;
         number_of_included_nodes++;
     }
     cout<<"excludes"<<endl;
    for(const auto& i: excludes){
         cout<<i<<endl;
     }
    //  for(const auto& i : include){
    //      for(size_t j = 0; i<adjList[i].size(); j++){
    //          if(find(include.begin(), include.end(), adjList[i][j])!= include.end()){
                 
    //          }
    //      }
    //  }
     auto trimedAdjList = trimAdjList(adjList, include, excludes, includemap);
     cout<<"after trimming"<<endl;
     for(size_t i = 0; i<trimedAdjList.size(); i++){
        cout<<i<<" -> ";
        for(size_t j = 0; j<trimedAdjList[i].size(); j++){
            cout<<trimedAdjList[i][j]<<" -> ";
        }
        cout<<endl;
    } 
     return 0;
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
