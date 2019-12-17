class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        int res = 0;
        while(p<nums.size()){
            if(nums[p]!=val){
                nums[res] = nums[p];
                res++;
            }
            p++;
        }
        return res;
    }
};
