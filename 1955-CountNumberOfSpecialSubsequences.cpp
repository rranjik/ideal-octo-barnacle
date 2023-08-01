class Solution {
public:
    bool compat(int l, int h){
        if(l==-1){
            return h==0;
        }
        if(l==0){
            return h==0||h==1;
        }
        if(l==1){
            return h==1||h==2;
        }
        if(l==2){
            return h==2;
        }
        return false;
    }
    vector<vector<int>> c;
    int dfs(int l, int i, int len, const vector<int>& a){
        if(i==n){
            if(l==2) return 1;
            return 0;
        }
        if(c[l+1][i]!=-1) return c[l+1][i];
        int res = 0;
        res+=(dfs(l, i+1, len, a)%mod);
        res%=mod;
        if(compat(l, a[i])){
            res+=(dfs(a[i], i+1, len+1, a)%mod);
            res%=mod;
        }
        return c[l+1][i] = res%mod;
    }
    int mod = 1e9+7;
    int n = 0;
    int countSpecialSubsequences(vector<int>& nums) {
        n = nums.size();
        c = vector<vector<int>>(4,vector<int>(n, -1));
        return dfs(-1, 0, 0, nums);
    }
};
