class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        vector<int> f(26);
        for(const auto& c : s) f[c-'a']++;
        int odd{};
        for(int i = 0; i<26; i++) odd+=f[i]%2;
        if(odd>k) return false;
        return true;
    }
};
