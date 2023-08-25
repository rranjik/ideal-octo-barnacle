class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long fs = 0; 
        long long rs = 0; 
        for(int i = 0; i<n; i++){
            fs+=grid[0][i];
        }
        long long res = numeric_limits<long long>::max();
        for(int i = 0; i<n; i++){
            fs-=grid[0][i];
            res = min(res, max(fs, rs));
            rs += grid[1][i];
        }
        return res;
    }
};
