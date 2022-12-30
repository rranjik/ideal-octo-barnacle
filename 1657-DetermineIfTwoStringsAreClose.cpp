class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        if(!word1.size()) return true;
        vector<int> f1(26);
        vector<int> f2(26);
        set<char> s1;
        set<char> s2;
        for(const auto& c : word1){
            s1.insert(c);
            f1[c-'a']++;
        }
        for(const auto& c : word2){
            s2.insert(c);
            f2[c-'a']++;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return s1==s2&&f1==f2;
    }
};
