class Solution {
public:
    vector<vector<int>> c;
    vector<int> n;
    int maxCoins(vector<int>& nums) {
        auto len = nums.size()+2;
        vector<int> nu(len, 1);
        for(int i = 1; i<len-1; i++){
            nu[i] = nums[i-1];
        }
        this->n = nu;
        c = vector<vector<int>>(len, vector<int>(len, 0));
        return dp(0, len-1);
    }
    int dp(int left, int right){
        if(right-left<=1) return  0;
        if(c[left][right]>0) return c[left][right];
        int res = 0;
        for(int i = left+1; i<right; i++){
            res = max(res, n[left]*n[i]*n[right]+dp(left, i)+dp(i, right));
        }
        c[left][right] = res;
        return res;
    }
};
