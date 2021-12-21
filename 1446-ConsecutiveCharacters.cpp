class Solution {
public:
    int maxPower(string s) {
        if(!s.length()) return 0;
        char c = s[0];
        int res= 1;
        int count = 1;
        for(int i = 1; i<s.length();){
            while(i<s.length()&&s[i]==c){
                count++;
                i++;
            }
            if(i<s.length())
                c = s[i];
            res = max(res, count);
            count = 0;
        }
        return res;
    }
};
