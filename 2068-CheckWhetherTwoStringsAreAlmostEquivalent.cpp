class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int> f1;
        unordered_map<char, int> f2;
        unordered_set<char> s;
        for(const auto& c : word1) {
            f1[c]++;
            s.insert(c);
        }
        for(const auto& c : word2) {
            f2[c]++;
            s.insert(c);
        }
        for(const auto& it : s){
            if(abs(f1[it]-f2[it])>3) return false;
        }
        return true;
    }
};
