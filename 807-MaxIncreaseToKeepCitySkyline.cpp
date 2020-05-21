class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> t(m, 0);
        vector<int> l(n, 0);
        for(int i = 0; i <n; i++){
            for(int j = 0; j<m; j++){
                l[j] = max(l[j], grid[i][j]);
            }
        }
        for(int j = 0; j <m; j++){
            for(int i = 0; i<n; i++){
                t[i] = max(t[i], grid[i][j]);
            }
        }
        int res = 0;
        for(const auto& s : t){
            cout<<s<<" ";
        }
        cout<<endl;
        for(const auto& s : l){
            cout<<s<<" ";
        }
        cout<<endl;
        for(int i = 0; i <n; i++){
            for(int j = 0; j<m; j++){
                int m = min(t[i], l[j]);
                res+=(m-grid[i][j]);
            }
        }
        return res;
    }
};
