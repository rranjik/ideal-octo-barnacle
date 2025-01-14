class Solution {
public:
    vector<int> a;
    unordered_map<int, int> m;
    int dp(int i){
        if(m.find(i)!=m.end()) return m[i];
        if(i>=n-1) return 0;
        int res = 1e9;
        int x = a[i];
        for(int j = 1; j<= a[i]; j++){
            res = min(res, dp(i+j)+1);
        }
        return m[i] = res;
    }
    int n;
    int jump(vector<int>& nums) {
        a = nums;
        n = a.size();
        return dp(0);
    }
};
