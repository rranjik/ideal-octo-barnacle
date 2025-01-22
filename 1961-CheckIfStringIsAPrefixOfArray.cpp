class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string c;
        for(const auto& w : words){
            c += w;
            if(c==s) return true;
        }
        return false;
    }
};
