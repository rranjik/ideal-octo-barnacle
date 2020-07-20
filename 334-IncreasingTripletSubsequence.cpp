class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = numeric_limits<int>::max();
        int c2 = numeric_limits<int>::max();
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<=c1){
                c1 = nums[i];
            }else if(nums[i]<=c2){
                c2 = nums[i];
            }else {
                return true;
            }
        }
        return false;
    }
};
