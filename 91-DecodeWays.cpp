class Solution {
public:
    unordered_map<string, int> c;
    int decode(string s){
        if(c.find(s)!=c.end())return c[s];
        if(s.length()==0) return 1;
        else {
            if(s.length()==1) {c[s] = 1; return 1;}
            int res = 0;
            int l = s[s.length()-1]-'0';
            int ll = s[s.length()-2]-'0';
            if(ll&&ll*10+l<=26) 
                res += decode(s.substr(0, s.length()-2));
            if(l)
                res += decode(s.substr(0, s.length()-1));
            //if(!ll&&l)
            //    return 0;
            c[s] =res;
            return res;
        }
    }
    int numDecodings(string s) {
        if(s=="0") return 0;
        if(s.length()>=1&&s[0]=='0') return 0;
        return decode(s);
    }
};
