
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
            childIncluded |= DFS(child, adjList, visited, include, cities);
        }
    }
    if(childIncluded)
        include[source] = true;
    return include[source];
}

vector<int> nodesToInclude(const vector<int>& cities, const vector<vector<int>>& adjList){
   vector<int> res;
   vector<bool> visited(adjList.size(), false);
   vector<bool> include(adjList.size(), false);
   DFS(cities[0]-1, adjList, visited, include, cities); 
   for(size_t i = 0; i< include.size(); i++){
       if(include[i]){
           res.push_back(i);
       }
   }
   return res;
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
     auto include = nodesToInclude(k, adjList);
     for(const auto& i: include){
         cout<<i<<endl;
     }
     for(const auto& i : include){
         for(size_t j = 0; i<adjList[i].size(); j++){
             if(find(include.begin(), include.end(), adjList[i][j])!= include.end()){
                 
             }
         }
     }
     return 0;
}
