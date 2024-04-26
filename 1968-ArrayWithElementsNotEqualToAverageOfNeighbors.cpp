class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res(n);
        int j = 0;
        for(int i = 0; i<n; j++,i+=2){
            res[i] = nums[j];
        }
        for(int i = 1; j<n; j++,i+=2){
            res[i] = nums[j];
        }
        return res;
    }
};
