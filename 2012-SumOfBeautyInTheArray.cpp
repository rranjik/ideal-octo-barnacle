class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> rmax = nums;
        vector<int> lmin = nums;
        int n = nums.size();
        int maxl = nums[0];
        int maxr = nums[n-1];
        for(int i = 1; i<n; i++){
            rmax[i] = max(rmax[i-1], nums[i]);
        }
        for(int i = n-2; i>=0; i--){
            lmin[i] = min(nums[i], lmin[i+1]);
        }
        int res = 0;
        for(int i = 1; i<=n-2; i++){
            if(nums[i]>rmax[i-1]&&lmin[i+1]>nums[i]){
                res += 2;
            }else if(nums[i-1]<nums[i]&&nums[i]<nums[i+1]){
                res+=1;
            }
        }
        return res;
    }
};
