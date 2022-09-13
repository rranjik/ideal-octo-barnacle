class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1;
        int pre = 0;
        int res{};
        for(int i = 1; i<s.size(); i++){
            if(s[i]==s[i-1]) cur++;
            else {
                res +=min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        res +=min(cur, pre);
        return res;
    }
};
