class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<=1000; i++){
            auto lb = lower_bound(nums.begin(), nums.end(), i);
            auto gte = distance(lb, nums.end());
            if(gte == i) return i;
        }
        return -1;
    }
};
