class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0; 
        int j = 0;
        int n = nums.size();
        long long sum = 0;
        long long len = 0;
        long long res = 0;
        while(j<n){
            len++;
            sum+=nums[j];
            auto score = sum*len;
            while(i<=j&&score>=k){
                sum-=nums[i];
                len--;
                score=sum*len;
                i++;
            }
            res+=(j-i+1);
            j++;
        }
        return res;
    }
};
