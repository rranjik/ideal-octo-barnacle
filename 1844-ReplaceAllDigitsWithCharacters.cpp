class Solution {
public:
    string replaceDigits(string s) {
        string res = s;
        for(int i = 1; i<s.size(); i+=2){
            res[i] = s[i-1]+(s[i]-'0');
        }
        return res;
    }
};
