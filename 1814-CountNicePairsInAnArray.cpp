class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<n; i++){
            auto n = nums[i];
            auto rns = to_string(nums[i]);
            reverse(rns.begin(), rns.end());
            auto rn = stoi(rns);
            nums[i] = n-rn;
            m[n-rn].push_back(i);
        }
        for(const auto& a : nums) cout<<a<<" "; cout<<endl;
        int res{};
        int mod = 1e9+7;
        for(int i = 0; i<n; i++){
            res += distance(upper_bound(m[nums[i]].begin(), m[nums[i]].end(), i), m[nums[i]].end());
            res %= mod;
        }
        return res;
    }
};
