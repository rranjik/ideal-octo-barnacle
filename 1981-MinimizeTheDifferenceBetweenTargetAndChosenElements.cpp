class Solution {
public:
    int m;
    int n;
    vector<set<int>> g;
    unordered_map<int, unordered_map<int, int>> dp;
    int t;
    int dfs(int i, int s){
        if(i>=m) return abs(s-t);
        if(dp.find(i)!=dp.end()&&dp[i].find(s)!=dp[i].end()) return dp[i][s];
        int res = 1e9;
        for(const auto& it : g[i]){
            res = min(res, dfs(i+1, s+it));
            //early exit if exact match
            //or if this is already more than target
            //remember that the numbers are all positive 
            //so s is going to get larger and the 
            //result is going to be worse if we continue
            //past s+it>t (provided that we sorted the row
            //using a std::set to begin with)
            if(res==0||s+it>t) break;
        }
        return dp[i][s] = res;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        t = target;
        m = mat.size();
        n = mat[0].size();
        g = vector<set<int>>(m);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                g[i].insert(mat[i][j]);
            }
        }
        return dfs(0, 0);
    }
};
