class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        if(m*n!=a.size()) return {};
        vector<vector<int>> res;
        int k = 0;
        for(int i = 0; i<m; i++){
            vector<int> row;
            for(int j = 0; j<n; j++){
                row.push_back(a[k]);
                k++;
            }
            res.push_back(row);
        }
        return res;
    }
};
