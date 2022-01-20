class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = numeric_limits<int>::min();
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                res = max(res, (nums[i]-1)*(nums[j]-1));
            }
        }
        return res;
    }
};
