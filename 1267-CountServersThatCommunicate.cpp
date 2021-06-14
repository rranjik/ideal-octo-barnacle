class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m, n;
        m = grid.size();
        if(!m) return 0;
        n = grid[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    rows[i]++; 
                    cols[j]++;
                }
            }
        }
        int res{};
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]&&(rows[i]>1||cols[j]>1))
                    res++;
            }
        }
        return res;
    }
};
