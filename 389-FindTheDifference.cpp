class Solution {
public:
    char findTheDifference(string s, string t) {
        char f{};
        for(const auto& c : s) f^=c;
        for(const auto& c : t) f^=c;
        return f;
    }
};
