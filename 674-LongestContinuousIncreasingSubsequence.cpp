class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int l = nums[0];
        int res = 1;
        int s = 1;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>l){
                s++;
            }else {
                s = 1;
            }
            res = max(res, s);
            l = nums[i];
        }
        return res;
    }
};
