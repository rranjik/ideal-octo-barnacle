class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int r = k%nums.size();
        int n = nums.size();
        if(!r) return;
        auto res = nums;
        for(int i = 0; i<nums.size(); i++){
            res[(i+r)%n] = nums[i];
        }
        nums = res;
    }
};
