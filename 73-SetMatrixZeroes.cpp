class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return;
        int n = matrix[0].size();
        auto zeroRow = -1;
        for(int i = 0; i<m; i++){
            bool foundFirstZero = false;
            bool zero = false;
            for(int j= 0; j<n; j++){
                if(!matrix[i][j]&&zeroRow==-1){
                    //found the first zero row
                    foundFirstZero = true;
                    zeroRow = i;
                    for(int k= 0; k<=j; k++) matrix[zeroRow][k] = 0;
                    matrix[zeroRow][j] = 1;
                }
                else if(!matrix[i][j]&&zeroRow!=-1&&!foundFirstZero){
                    //this is not the zero row we now one already
                    matrix[zeroRow][j] = 1;
                    zero = true;
                }
                else if(!matrix[i][j]&&zeroRow!=-1&&foundFirstZero){
                    //this is not the zero row we now one already
                    matrix[zeroRow][j] = 1;
                }else if(matrix[i][j]&&foundFirstZero){
                    matrix[i][j] = 0;
                }
            }
            if(foundFirstZero) foundFirstZero = false;
            if(zero){
                for(int k = 0; k<n; k++){
                    matrix[i][k] = 0;
                }
            }
        }
        if(zeroRow==-1) return;
        for(int j = 0; j<n; j++){
            if(matrix[zeroRow][j]){
                for(int i = 0; i<m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
