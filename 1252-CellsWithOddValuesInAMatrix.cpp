class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> r(n, 0);
        vector<int> c(m, 0);
        for(int i = 0; i<indices.size(); i++){
            r[indices[i][0]]++;
            c[indices[i][1]]++;
        }
        int ocols = 0;
        for(int i = 0; i<m; i++){
            if(c[i]%2) ocols++;
        }
        int res = 0;
        for(int i = 0; i<n; i++){
            if(r[i]%2){
                res+=(m-ocols);
            }else res+=(ocols);
        }
        return res;
    }
};
