class SubrectangleQueries {
public:
    //rectangle and updates
    vector<vector<int>> r, u;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        r = rectangle;
    }
    
    void updateSubrectangle(int r1, int c1, int r2, int c2, int n) {
        u.push_back({r1, c1, r2, c2, n});
    }
    
    int getValue(int row, int col) {
        for(int i = u.size()-1; i>=0; i--){
            auto up = u[i];
            if(row>=up[0]&&col>=up[1]&&row<=up[2]&&col<=up[3]) return up[4];
        }
        return r[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
