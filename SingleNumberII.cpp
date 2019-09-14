class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long res = 0;
        for(int i = 0; i<32; i++){
            long inter = 0;
            for(int j = 0; j<nums.size(); j++){
                inter+=(nums[j]>>i)&1;
            }
            res |= ((inter%3)<<i);
        }
        return res;
    }
};
