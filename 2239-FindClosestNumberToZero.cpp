class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = -1e9;
        int md = 1e9;
        for(int i = 0; i<nums.size(); i++){
            if(md>(abs(nums[i]-0))){
                md = abs(nums[i]-0); 
                res = nums[i];
            }else if(md==(abs(nums[i]-0))){
                res = max(res, nums[i]);
            }
        }
        return res;
    }
};
