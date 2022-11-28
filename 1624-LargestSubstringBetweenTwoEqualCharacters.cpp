class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, pair<int, int>> m;
        for(int i = 0; i<s.length(); i++){
            auto c = s[i];
            if(m.find(c)!=m.end()){
                m[c].second = i;
            }
            else {
                m[c].first = i;
            }
        }
        int res = -1;
        for(const auto& it : m){
            auto p = it.second;
            res = max(res, p.second-p.first-1);
        }
        return res;
    }
};
