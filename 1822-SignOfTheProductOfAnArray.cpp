class Solution {
public:
    int arraySign(vector<int>& nums) {
        int s = 1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                s*=1;
            }else if(nums[i]<0){
                s*=-1;
            }else{
                s*=0;
            }
        }
        return s;
    }
};
