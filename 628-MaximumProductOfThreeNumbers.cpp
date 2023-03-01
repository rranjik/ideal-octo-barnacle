class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res{};
        if(nums.size()==3) return nums[0]*nums[1]*nums[2];
        int n = nums.size();
        return max({
            nums[0]*nums[1]*nums[n-1],
            nums[n-3]*nums[n-2]*nums[n-1]
        });
    }
};
