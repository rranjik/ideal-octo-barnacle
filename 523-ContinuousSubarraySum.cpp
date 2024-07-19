class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1) return false;
        int n = nums.size();
        vector<int> presums(n+1);
        for(int i = 0; i<n; i++){
            presums[i+1] = presums[i]+nums[i];
        }
        //for(const auto& s: presums) cout<<s<<" "; cout<<endl;
        for(auto& s: presums) s%=k;
        //for(const auto& s: presums) cout<<s<<" "; cout<<endl;
        unordered_map<int, int> modcounts;
        for(int i = 1; i<presums.size(); i++){
            auto s = presums[i];
            auto sprev = presums[i-1];
            if(modcounts[s]>=1) return true;
            modcounts[sprev]++;
            //for(const auto& [mod, cnt]:modcounts) cout<<mod<<" "<<cnt<<"; "; cout<<endl;
        }
        return false;
    }
};
