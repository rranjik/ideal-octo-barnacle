class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(); 
        if(!m) return {};
        int n = grid[0].size();
        auto res = grid;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int a = i*n+j;
                a+=k;
                a%=(m*n);
                auto r = a/n;
                auto c = a%n;
                cout<<" a = "<<a<<" r = "<<r<<" c = "<<c<<endl;
                res[r][c] = grid[i][j];
            }
        }
        return res;
    }
};
