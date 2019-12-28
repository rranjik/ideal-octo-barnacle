class NumMatrix {
    vector<vector<int>> t;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return;
        t = vector<vector<int>> (matrix.size()+1, vector<int>(matrix[0].size()+1));
        for(int i = 1; i<t.size(); i++){
            for(int j = 1; j<t[0].size(); j++){
                t[i][j] = t[i-1][j]+t[i][j-1]+matrix[i-1][j-1]-t[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return t[row2+1][col2+1] - t[row1][col2+1] - t[row2+1][col1] + t[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
