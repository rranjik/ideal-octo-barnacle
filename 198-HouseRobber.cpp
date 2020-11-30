class Solution {
public:
    vector<int> c;
    int dp(int i){
        if(i<0) return 0;
        if(c[i]!=-1) return c[i];
        int res = 0;
        res = max(dp(i-1), dp(i-2)+n[i]);
        c[i] = res;
        return res;
    }
    vector<int> n;
    int rob(vector<int>& nums) {
        n = nums;
        c = vector<int>(nums.size(), -1);
        return dp(nums.size()-1);
    }
};
