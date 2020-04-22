class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp = matrix; //(r, vector<int>(c, 0));
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(matrix[i][j]){
                    res+=1;
                    int ul = 0;
                    int u = 0;
                    int l = 0;
                    if(i-1>=0&&j-1>=0) ul = dp[i-1][j-1];
                    if(i-1>=0) u = dp[i-1][j];
                    if(j-1>=0) l = dp[i][j-1];
                    res += (min(u, min(ul, l))+1)-1;
                    dp[i][j] = min(u, min(ul, l))+1;
                }
            }
        }
        return res;
    }
};
