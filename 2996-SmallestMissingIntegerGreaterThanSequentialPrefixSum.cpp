class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 1;
        unordered_set<int> s(nums.begin(), nums.end());
        int sum = nums[0];
        while(i<nums.size()){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
                i++;
                continue;
            }else break;
        }
        if(i==nums.size()) {
            if(s.find(sum)==s.end()) return sum;
            return sum+1;
        }
        while(s.find(sum)!=s.end()) sum++;
        return sum;
    }
};
