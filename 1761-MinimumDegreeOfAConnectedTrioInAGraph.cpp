class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjm(n, vector<int>(n));
        vector<vector<int>> adjl(n);
        for(int i = 0; i<edges.size(); i++){
            cout<<"i = "<<i<<endl;
            auto u = edges[i][0]-1;
            auto v = edges[i][1]-1;
            adjm[u][v] = 1;
            adjm[v][u] = 1;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        cout<<"adj done"<<endl;
        unordered_set<int> st;
        int res = 1e9;
        bool found = false;
        for(int i = 0; i<n; i++){
            //cannot be a trio
            if(adjl[i].size()<2) continue;
            for(const auto& j : adjl[i]){
                for(const auto& k : adjl[i]){
                    if(j==k) continue;
                    if(adjm[j][k]==0) continue;
                    found = true;
                    res = min(res, (int)(adjl[i].size()-2+ adjl[j].size()-2+ adjl[k].size()-2)); 
                } 
            }
        }
        return found ? res : -1;
    }
};
