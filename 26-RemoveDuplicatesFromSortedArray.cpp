class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int sp = 0;
        int fp = 0;
        while(fp<nums.size()){
            if(nums[sp]!=nums[fp]){
                sp++;
                nums[sp] = nums[fp];
            }
            fp++;
        }
        return sp+1;
    }
};
