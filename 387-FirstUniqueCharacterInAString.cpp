class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26, 0);
        vector<int> in(26, s.length());
        for(int i = 0; i<s.length(); i++){
            f[s[i]-'a']++;
            if(f[s[i]-'a']==1) in[s[i]-'a'] = i;
            if(f[s[i]-'a']>1) in[s[i]-'a'] = s.length();
        }
        int res = s.length();
        for(const auto& n : in){
            res = min(res, n);
        }
        if(res==s.length()) return -1;
        return res;
    }
};
