class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> f(26);
        int i = 0;
        int j = 0;
        for(; i<s.length()&&j<t.length(); j++){
            if(t[j]==s[i]) i++;
        }
        if(i==s.length()) return true;
        return false;
    }
};
