class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==target){
                res.push_back(i);
            }
        }
        return res;
    }
};
