class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto s: words){
            auto w = s;
            reverse(s.begin(), s.end());
            if(w==s) return w;
        }
        return "";
    }
};
