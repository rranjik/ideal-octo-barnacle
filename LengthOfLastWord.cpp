class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int r = 0;
        while(s[r]==' ')
            r++;
        int c = 0;
        while(r<s.length()){
            if(s[r]!=' '){
               c++;
               r++;
            }
            else break;
        }
        return c;
    }
};
