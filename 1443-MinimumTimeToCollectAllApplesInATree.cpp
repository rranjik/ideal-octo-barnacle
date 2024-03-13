class Solution {
public:
    pair<int, bool> dfs(int src, int par, 
        const vector<vector<int>>& adjl, 
        const vector<bool>& has){
        pair<int, bool> res = {0, false};
        if(has[src]) {
            res.second = true;
        }
        for(const auto& v: adjl[src]){
            if(v==par) continue;
            auto [vstep, vapple] = dfs(v, src, adjl, has);
            res.first += vstep;
            res.second |= vapple;
        }
        if(res.second) res.first+=2;
        cout<<src<<" returns "<<res.first<<endl;
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //v = vector<bool>(n);
        vector<vector<int>> adjl(n);
        for(const auto& e : edges){
            auto u = e[0]; auto v = e[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        auto res = dfs(0, -1, adjl, hasApple);
        return res.first?res.first-2:0;
    }
};
