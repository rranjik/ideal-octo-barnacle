class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rf(26, 0);
        vector<int> mf(26, 0);
        for(const auto& c : ransomNote) rf[c-'a']++;
        for(const auto& c : magazine) mf[c-'a']++;
        for(int i = 0; i<26; i++) if(rf[i]>mf[i]) return false;
        return true;
    }
};
