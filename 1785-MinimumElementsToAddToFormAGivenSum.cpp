class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum{};
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum==goal) return 0;
        auto diff = abs(goal-sum);
        return diff/limit + ((diff%limit)?1:0);
    }
};
