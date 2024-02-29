class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int expect = nums[0]+1;
        for(int i = 1; i <nums.size(); i++){
            if(nums[i]!=expect){
                int missed = nums[i]-expect;
                if(k<=missed){
                    return expect+k-1;
                }
                k-=missed;
            }
            expect = nums[i]+1;
        }
        return nums[nums.size()-1]+k;
    }
}
