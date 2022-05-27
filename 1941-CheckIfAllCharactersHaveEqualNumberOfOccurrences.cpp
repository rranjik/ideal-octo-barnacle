class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> m;
        int req=0;
        for(const auto& c : s){
            m[c]++;
            req = m[c];
        }
        for(const auto& it : m){
            if(it.second!=req) return false;
        }
        return true;
    }
};
