class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = 1e9;
        int n = nums.size();
        if(k==1) return 0;
        for(int i = 0; i<=n-k; i++){
            cout<<"i = "<<i<<endl;
            res = min(res, nums[i+k-1]-nums[i]);
        }
        return res;
    }
};
