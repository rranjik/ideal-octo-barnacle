class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(const auto& s : strs){
            auto c = s;
            sort(c.begin(), c. end());
            m[c].push_back(s);
        }
        for(const auto& p : m){
            res.push_back(p.second);
        }
        return res;
    }
};
