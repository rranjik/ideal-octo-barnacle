class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> b(m, vector<int>(n, 0));
        for(int i = 0; i<n; i++){
            b[0][i] = 1;
        }
        for(int i = 0; i<m; i++){
            b[i][0] = 1;
        }
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                b[i][j] = b[i-1][j] + b[i][j-1];
            }
        }
        return b[m-1][n-1];
    }
};
