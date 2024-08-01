class Solution {
public:
    bool removeOnes(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                auto sum = (g[0][0]+g[0][j]+g[i][0]+g[i][j]);
                if(sum%2) return false;
            }
        }
        return true;
    }
};
