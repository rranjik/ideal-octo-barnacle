class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) { 
        if(!nums.size()) return 0;
        auto c = nums;
        sort(c.begin(), c.end());
        int s = 0;
        int e = 0;
        bool foundf = false;
        bool foundl = false;
        for(int i = 0; !foundf&&i<nums.size(); i++){
            if(c[i]!=nums[i]){
                s = i;
                foundf = true;
            }
        }
        if(foundf){
            for(int i = nums.size()-1; !foundl&&i>=0; i--){
                if(c[i]!=nums[i]){
                    e = i;
                    foundl = true;
                }
            }
            return e-s+1;
        }
        else return 0;
    }
};
