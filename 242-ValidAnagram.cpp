class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> fs;
        unordered_map<char, int> ft;
        for(const auto& c : s){
            fs[c]++;
        }
        for(const auto& c : t){
            ft[c]++;
        }
        return fs == ft;
    }
};
