class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> b(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int res = 0;
        for(int i = 1; i< matrix.size()+1; i++){
            for(int j = 1; j <matrix[0].size()+1; j++){
                //cout<<"i = "<<i<<"; j = "<<j<<endl;
                if(matrix[i-1][j-1] == '0'){
                    b[i][j] = 0;
                }
                else{
                    //cout<<"no it is one"<<endl;
                    b[i][j] = min(b[i-1][j-1], min(b[i-1][j], b[i][j-1]))+1;
                }
                //cout<<"outside else"<<endl;
                //cout<<"b[i][j] = "<<b[i][j]<<endl;
                res = max(res, b[i][j]);
            }
        }
        return res*res;
    }
};
