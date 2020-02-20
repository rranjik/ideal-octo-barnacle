class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i< numRows+1; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j<i; j++){
                row.push_back(res[i-1][j]+res[i-1][j-1]);
            }
            if(i)
                row.push_back(1);
            res.push_back(row);
        }
        //for(const auto& row : res){
        //    for(const auto& n : row){
        //        cout<<n<<" ";
        //    }
        //    cout<<endl;
        //}
        return res[numRows];
    }
};
