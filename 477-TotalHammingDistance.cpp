class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        if(nums.size()==0) return 0;
        vector<int> ones(32, 0);
        vector<int> zeros(32, 0);
        for(int i = 0; i<nums.size(); i++){
            bitset<32> b = nums[i];
            for(int i = 0; i<32; i++){
                if(b[i]){
                    ones[i]++;
                }else{
                    zeros[i]++;
                }
            }
        }
        
        for(int i = 0; i<32; i++){
            res+=(ones[i]*zeros[i]);
        }
        return res;
    }
};
