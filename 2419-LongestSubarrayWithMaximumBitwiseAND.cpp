class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            int j = i;
            while(i<nums.size()&&nums[i]==mx){
                res = max(res, i-j+1);
                i++;
            }
        }
        return res;
    }
};
