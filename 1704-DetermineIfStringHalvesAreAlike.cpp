class Solution {
public:
    bool halvesAreAlike(string s) {
        bool res = false;
        int c1{};
        int c2{};
        for(int i = 0; i<s.size()/2; i++){
            if(s[i]=='a'||
                s[i]=='e'||
                s[i]=='i'||
                s[i]=='o'||
                s[i]=='u'||
                s[i]=='A'||
                s[i]=='E'||
                s[i]=='I'||
                s[i]=='O'||
                s[i]=='U') c1++;
        }
        for(int i = s.size()/2; i<s.size(); i++){
            if(s[i]=='a'||
                s[i]=='e'||
                s[i]=='i'||
                s[i]=='o'||
                s[i]=='u'||
                s[i]=='A'||
                s[i]=='E'||
                s[i]=='I'||
                s[i]=='O'||
                s[i]=='U') c2++;
        }
        return c1==c2;
    }
};
