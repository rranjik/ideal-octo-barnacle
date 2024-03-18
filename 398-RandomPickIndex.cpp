class Solution {
public:
    map<int, vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int lo = 0;
        int hi = m[target].size()-1;
        random_device rd;
        mt19937 twist(rd());
        uniform_int_distribution<int> dist(0, hi);
        auto idx = dist(twist);
        return m[target][idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
