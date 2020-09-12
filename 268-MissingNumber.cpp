class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bool zerofound = false;
        for(int i = 0; i<nums.size(); i++){
            nums[i]++;
        }
        for(int i = 0; i<nums.size(); i++){
            //if(nums[i]==0) zerofound = true; 
            int an = abs(nums[i])-1;
            if(an<nums.size()){
                nums[an] = -nums[an];
            }
        }
        //if(!zerofound) return 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>0){
                return i;
            }
        }
        return nums.size();
    }
};
