class Solution {
public:
    vector<bool> v;
    pair<int, int> dfs(int s, const vector<vector<int>>& adjl){
        v[s] = true;
        int h = 0, d = 0, h1 = 0, h2 = 0;
        for(int i = 0; i<adjl[s].size(); i++){
            if(!v[adjl[s][i]]){
                auto r = dfs(adjl[s][i], adjl);
                d = max(d, r.first);
                h = max(h, r.second+1);
                if(h1<r.second){
                    h2 = h1;
                    h1 = r.second;
                }else if(h2<r.second){
                    h2 = r.second;
                }
            }
        }
        d = max(d, h1+h2+2);
        return {d, h};
    }
    int treeDiameter(vector<vector<int>>& edges) {
        vector<vector<int>> adjl = vector<vector<int>>(edges.size()+1);
        v = vector<bool>(edges.size(), false);
        for(int i = 0; i<edges.size(); i++){
            adjl[edges[i][0]].push_back(edges[i][1]);
            adjl[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0, adjl).first;
    }
};
