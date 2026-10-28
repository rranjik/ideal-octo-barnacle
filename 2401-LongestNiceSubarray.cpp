class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used = 0;
        int res = 0;
        for(int i = 0, j = 0; i<nums.size(); i++){
            while((used&nums[i])!=0){
                used^=nums[j];
                j++;
            }
            used|=nums[i];
            res = max(res, i-j+1);
        }
        return res;
    }
};
