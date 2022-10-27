class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        if(!m) return 0;
        int n = mat[0].size();
        vector<int> rs;
        vector<int> cs;
        for(int i = 0; i<m; i++){
            int rsi{};
            for(int j = 0; j<n; j++){
                rsi+=mat[i][j];
            }
            rs.push_back(rsi);
        }
        for(int j = 0; j<n; j++){
            int csi{};
            for(int i = 0; i<m; i++){
                csi+=mat[i][j];
            }
            cs.push_back(csi);
        }
        int res{};
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j]&&rs[i]==1&&cs[j]==1) res++;
            }
        }
        return res;
    }
};
