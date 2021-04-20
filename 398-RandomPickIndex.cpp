class Solution {
public:
    unordered_map<int, vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++) m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist6(0,m[target].size()-1);
        return m[target][dist6(rng)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
