class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res{9999};
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==target){
                if(res>abs(i-start))
                    res =abs(i-start); 
            }
        }
        return res;
    }
};
