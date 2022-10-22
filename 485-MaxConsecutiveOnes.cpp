class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res{};
        int curr{};
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]){
                curr++;
            }else{
                res = max(res, curr);
                curr=0;
            }
        }
        res = max(res, curr);
        return res;
    }
};
