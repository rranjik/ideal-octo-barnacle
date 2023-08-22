class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> rm(n);
        int msf = -1e9;
        for(int i =n-1; i>=0; i--){
            msf = max(nums[i], msf);
            rm[i] = msf;
        }
        int res = -1;
        for(int i =0; i<n-1; i++){
            res = max(res, rm[i+1]-nums[i]);
        }
        if(res==0) return -1;
        return res;
    }
};
