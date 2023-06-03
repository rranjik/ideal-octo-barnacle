class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> f(26);
        for(const auto& c : s){
            f[c-'a']++;
        }
        for(const auto& n : f){
            if(!n) return false;
        }
        return true;
    }
};
