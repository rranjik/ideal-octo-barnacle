class Solution {
public:
    int ds(int b){
        int res = 0;
        while(b){
            res += b%10;
            b/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int, greater<int>>> m;
        for(int i = 0; i<nums.size(); i++){
            m[ds(nums[i])].insert(nums[i]);
        }
        int res = -1;
        for(const auto& [dss, ns]: m){
            if(ns.size()>=2){
                res = max(res, *ns.begin()+ *next(ns.begin()));
            }
        }
        return res;
    }
};
