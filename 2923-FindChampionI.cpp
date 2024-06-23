class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> t(n);    
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i==j) continue;
                if(grid[i][j]) t[j]++;
            }
        }
        int res = -1;
        for(int i = 0; i<n; i++){
            if(t[i]==0) {
                if(res==-1) res = i;
                else return -1;
            }
        }
        return res;
    }
};
