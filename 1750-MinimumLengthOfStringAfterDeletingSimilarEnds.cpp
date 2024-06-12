class Solution {
public:
    int ml(const string& s, int i, int j){
        if(i==j) return 1;
        if(i>j) return 0;
        if(s[i]!=s[j]) return j-i+1;
        auto f = s[i];
        while(i<s.size()&&s[i]==f) i++;
        while(j>=0&&s[j]==f) j--;
        return ml(s, i, j);
    }
    int minimumLength(string s) {
        return ml(s, 0, s.size()-1);
    }
};
