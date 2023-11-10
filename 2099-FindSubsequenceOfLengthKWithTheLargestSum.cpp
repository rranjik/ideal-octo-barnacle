class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for(int i = 0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int g = 0;
        auto rres = vector<pair<int, int>>(v.end()-k, v.end());
        sort(rres.begin(), rres.end(), [](const auto& a, const auto& b){return a.second<b.second;});
        vector<int> res;
        for(int i = 0; i<rres.size(); i++){
            res.push_back(nums[rres[i].second]);
        }
        return res;
    }
};
