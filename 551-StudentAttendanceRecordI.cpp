class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("LLL")!=string::npos) return false;
        int na{};
        for(const auto& c : s) if(c=='A') na++;
        return na<=1;
    }
};
