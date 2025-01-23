class Solution {
public:
    int longestContinuousSubstring(string s) {
        char last = s[0];
        int curr = 1;
        int res = 0;
        for(int i = 1; i<s.size(); i++){
            if(last==s[i]-1){
                curr++;
            }else{
                res = max(res, curr);
                curr = 1;
            }
            last = s[i];
        }
        res = max(res, curr);
        return res;
    }
};
