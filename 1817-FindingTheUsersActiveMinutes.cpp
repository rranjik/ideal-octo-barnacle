class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> um;
        for(const auto& l : logs){
            auto u = l[0];
            auto m = l[1];
            um[u].insert(m);
        }
        map<int, int> uam;
        vector<int> res(k);
        for(const auto& it : um){
            auto i = it.second.size();
            res[i-1]++;
        }
        return res;
    }
};
