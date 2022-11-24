class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res{};
        for(int i = 0; i<mat.size(); i++){
            res+=mat[i][i];
        }
        for(int i = mat.size()-1, j = 0; i>=0; j++, i--){
            if(i!=j)
                res+=mat[i][j];
        }
        return res;
    }
};
