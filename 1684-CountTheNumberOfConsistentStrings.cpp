class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> f(26);
        for(const auto& c : allowed){
            f[c-'a']++;
        }
        int res{};
        for(const auto& w : words){
            auto rf = f;
            bool con = true;
            for(const auto& c : w){
                if(rf[c-'a']){
                    
                }
                else {
                    con = false;
                    break;
                }
            }
            if(con) res++;
        }
        return res;
    }
};
