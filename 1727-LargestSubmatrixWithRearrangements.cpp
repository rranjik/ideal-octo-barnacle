class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pm = vector<vector<int>>(m, vector<int>(n));
        for(int j = 0; j<n; j++){
            int l = 0;
            for(int i = 0; i<m; i++){
                if(l&&mat[i][j]){
                    pm[i][j] = pm[i-1][j]+1;
                }
                else if(!l&&mat[i][j]){
                    pm[i][j] = 1;
                    l = 1;
                }
                else if(!l&&!mat[i][j]){
                    
                }
            }
        }
        //for(const auto& r : pm){
        //    for(const auto& c : r){
        //        cout<<c<<" ";
        //    }
        //    cout<<endl;
        //}
        int res{};
        for(auto& r : pm){
            sort(r.begin(), r.end());
            for(int i = 0; i<r.size(); i++){
                int ne = n-i;
                res = max(res, ne*r[i]);
            }
        }
        return res;
    }
};
