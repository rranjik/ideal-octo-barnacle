class Solution {
public:
    int dp(int i, int rs){
        if(i<0){
            if(rs==t)
            return 1;
            else return 0;
        }
        int res = 0;
        int add = dp(i-1, rs+nums[i]);
        int sub = dp(i-1, rs-nums[i]);
        res += add;
        res += sub;
        return res;
    }
    int t;
    vector<int> nums;
    int findTargetSumWays(vector<int>& nums, int S) {
        this->t = S;
        this->nums = nums;
        return dp(nums.size()-1, 0);
    }
};
