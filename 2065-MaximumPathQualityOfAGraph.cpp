class Solution {
public:
    vector<vector<pair<int, int>>> adjl;
    vector<int> v;
    vector<int> vals;
    int res = 0;
    void dfs(int i, int tl, int cur){
        v[i]++;
        if(v[i]==1) cur+=vals[i];
        if(i==0) res = max(res, cur);
        for(const auto& [c, t] : adjl[i]){
            if(tl-t>=0){
                dfs(c, tl-t, cur);
            }
        }
        v[i]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vals = values;
        int n = values.size();
        adjl = vector<vector<pair<int, int>>>(n);
        v = vector<int> (n);
        for(const auto& e : edges){
            adjl[e[0]].push_back({e[1], e[2]});
            adjl[e[1]].push_back({e[0], e[2]});
        }
        dfs(0, maxTime, 0);
        return res;
    }
};
