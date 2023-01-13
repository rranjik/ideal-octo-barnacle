class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        //just do as asked
        int m = g.size();
        int n = g[0].size();
        vector<int> r(m), c(n);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(g[i][j]){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for(const auto& x : r) cout<<x<<" "; cout<<endl;
        for(const auto& x : c) cout<<x<<" "; cout<<endl;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                g[i][j] = r[i]+c[j]-(m-r[i])-(n-c[j]);
            }
        }
        return g;
    }
};
