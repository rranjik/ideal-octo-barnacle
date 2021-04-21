class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int last = nums[0];
        int res{};
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<= last){
                res+= ((last+1) - nums[i]);
                last = last+1;
            }else{
                last = nums[i];
            }
        }
        return res;
    }
};
