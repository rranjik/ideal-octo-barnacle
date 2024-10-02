class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& arr) {
        sort(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        
        auto g = arr[0];
        for(int i = 1; i<arr.size(); i++){
            g = gcd(g, arr[i]);
        }
        
        for(int i = 0; i<nums.size(); i++){
            if((g%nums[i])==0) return i;
        }
        return -1;
    }
};
