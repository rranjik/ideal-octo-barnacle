class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, vector<int>> m;
        for(int i = 0; i<s.size(); i++){
            m[s[i]].push_back(i);
        }
        long long res = 0;
        for(const auto& it : m){
            int sz = it.second.size();
            for(int i = 0; i<it.second.size(); i++){
                res += (sz-i);
            }
        }
        return res;
    }
};
