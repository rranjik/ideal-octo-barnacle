class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> res(m, vector<int> (n));
        for(int i = 0; i<M.size(); i++){
            for(int j = 0; j<M[i].size(); j++){
                double s{};
                int t{};
                if(i-1>=0&&j-1>=0) { s+=M[i-1][j-1]; t++; }
                if(i-1>=0) {t++; s+=M[i-1][j];}
                if(i-1>=0&&j+1<n) {t++; s+=M[i-1][j+1];}
                if(j-1>=0) {t++; s+=M[i][j-1];}
                if(j+1<n) {t++; s+=M[i][j+1];}
                if(i+1<m&&j-1>=0) {t++; s+=M[i+1][j-1];}
                if(i+1<m) {t++; s+=M[i+1][j];}
                if(i+1<m&&j+1<n) {t++; s+=M[i+1][j+1];}
                t++;
                s+=M[i][j];
                cout<<"i = "<<i<<" j = "<<j<<" t = "<<t<<" s = "<<s<<endl;
                s/=t;
                res[i][j] = s;
            }
        }
        return res;
    }
};
