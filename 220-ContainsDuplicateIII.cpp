class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for(int i = 0; i< nums.size(); i++){
            if(i-j>k){
                m.erase(nums[j]);
                j++;
            }
            auto lb = m.lower_bound((long long)nums[i]-t);
            if(lb!=m.end()){
                if(abs(lb->first - nums[i])<=t) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
