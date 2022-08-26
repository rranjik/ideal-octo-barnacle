class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        int neg = 0;
        int minn = numeric_limits<int>::max();
        long long res = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(g[i][j]<0) neg++;
                minn = min(minn, abs(g[i][j]));
                res+=abs(g[i][j]);
            }
        }
        cout<<minn<<" "<<res<<endl;
        if(neg%2) return res+(-2*minn);
        return res;
    }
};
