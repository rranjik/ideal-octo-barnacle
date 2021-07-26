class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        while(left<=right){
            int e = left+(right-left)/2;
            auto r = e/n;
            auto c = e%n;
            cout<<"l = "<<left<<"; r = "<<right
                <<"; e = "<<e<<"; r = "<<r<<"; c = "<<c<<endl;
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target){
                right = e-1;
            }else {
                left = e+1;
            }
        }
        return false;
    }
};
