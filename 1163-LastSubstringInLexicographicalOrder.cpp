class Solution {
public:
    string lastSubstring(string s) {
        int i = 0; int j = 1; int k = 0;
        while(j+k<s.length()){
            if(s[i+k]==s[j+k]) { k++; continue; }
            if(s[i+k]>s[j+k]) j = j+1;
            else {i = j; j=i+1; }
            if(i==j) j++;
            k = 0;
        }
        return s.substr(i, -1);
        if(i<j) return s.substr(i, -1);
        return s.substr(j, -1);
    }
};
