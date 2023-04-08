class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(!k) return 0;
        int p = 1;
        int res{};
        for(int i = 0, j = 0; j<nums.size(); j++){
            p*=nums[j];
            while(i<=j&&p>=k){
                p/=nums[i];
                i++;
            }
            if(p<k) res+=j-i+1;
        }
        return res;;
    }
};
