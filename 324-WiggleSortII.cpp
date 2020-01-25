class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res;
        for(int i = 0, f=((n)/2), b = n-1; i<n; i+=2, f--, b--){
            res.push_back(nums[f]);
            if(b>(n/2)) res.push_back(nums[b]);
        }
        nums = res;
    }
};
