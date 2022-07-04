class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i <nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        set<int> res;
        for(const auto& in : m[key]){
            for(int j = in-k; j<=in+k; j++){
                if(j>=0&&j<nums.size())
                    res.insert(j);
            }
        }
        return {res.begin(), res.end()};
    }
};
