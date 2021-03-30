class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int count = 0;
        for(int i = 0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                auto ab = nums[i]+nums[j];
                auto it = lower_bound(nums.begin()+j, nums.end(), ab);
                it--;
                count += distance(nums.begin()+j, it)>=0?distance(nums.begin()+j, it):0;
            }
        }
        return count;
    }
};
