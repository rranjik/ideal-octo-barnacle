class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(!nums.size()) return -1;
        if(nums.size()==1) return 0;
        vector<int> cum(nums.size());
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            cum[i] = sum;
        }
        for(int i = 0; i<nums.size(); i++){
            if(!i){
                if(cum[nums.size()-1]==cum[i]) return 0;
            }else{
                if(cum[i-1] == cum[nums.size()-1]-cum[i]) return i;
            }
        }
        return -1;
    }
};
