class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
            return false;
        int m = matrix.size();
        int n = matrix[m-1].size();
        if(target<matrix[0][0] || target>matrix[m-1][n-1])
            return false;
        int x = matrix.size()-1;
        int y = 0;
        while(x>=0&&y<n){
            if(matrix[x][y]==target)
                 return true;
            else if(matrix[x][y]>target)
                x--;
            else y++;
        }
        return false;
    }
};
