class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int, bool>> conn;
        vector<int> d(n, 0);
        int f = -1;
        int s = -1;
        int res{};
        for(const auto& r : roads){
            auto u = r[0];
            auto v = r[1];
            conn[u][v] = true;
            conn[v][u] = true;
            d[u]++;
            d[v]++;
        }
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                bool ij = false;
                if(conn.find(i)!=conn.end()&&conn[i].find(j)!=conn[i].end()) ij = true;
                res = max(res, d[i]+d[j]+(ij?-1:0));
            }
        }
        return res;
    }
};
