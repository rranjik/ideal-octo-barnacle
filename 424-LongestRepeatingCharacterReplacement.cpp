class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0; 
        int maj = 0;
        int start = 0;
        int end = 0;
        vector<int> f(26);
        while(end<s.length()){
            maj = max(maj, ++f[s[end]-'A']);
            if(end-start+1-maj>k){
                --f[s[start]-'A'];
                start++;
            }
            res = max(res, end-start+1);
            end++;
        }
        return res;
    }
};
