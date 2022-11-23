class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res{};
        int tinc{};
        int maxmult{};
        for(int i = 0; i<nums.size(); i++){
            int multhere{};
            int inchere{};
            while(nums[i]){
                while(nums[i]%2==0){
                    nums[i]/=2;
                    multhere++;
                }
                inchere++;
                nums[i]--;
            }
            tinc+=inchere;
            maxmult = max(maxmult, multhere);
        }
        return maxmult+tinc;
    }
};
