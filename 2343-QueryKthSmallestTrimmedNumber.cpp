class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        int nn = nums[0].size();
        for(const auto& q : queries){
            vector<pair<string, int>> v;
            auto k = q[0];
            auto t = q[1];
            for(int i = 0; i<n; i++){
                v.push_back({nums[i].substr(nn-t), i});
            }
            sort(v.begin(), v.end());
            res.push_back(v[k-1].second);
        }
        return res;
    }
};
