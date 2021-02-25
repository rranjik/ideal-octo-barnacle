class Solution {
public:
    int inf = numeric_limits<int>::max();
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char, char> m;
        vector<int> shifts(256, inf);
        for(int i = 0; i<s.size(); i++){
            if(shifts[(int)s[i]]==inf){
                shifts[(int)s[i]] = (int)(t[i]-s[i]);
                if(m.find(t[i])!=m.end()) return false;
                m[t[i]] = s[i];
            }else{
                if((char)(s[i]+shifts[s[i]]) != t[i])
                    return false;
            }
        }
        return true;
    }
};
