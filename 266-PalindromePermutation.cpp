class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> f;
        for(const auto& c : s){
            f[c]++;
        }
        int odd = 0;
        for(const auto& it : f){
           if(it.second%2) odd++;
           if(odd>=2) return false;
        }
        return true;
    }
};
