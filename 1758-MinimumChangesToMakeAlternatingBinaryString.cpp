class Solution {
public:
    int minOperations(string s) {
        int zf{};
        int of{};
        char n = '0';
        for(int i = 0; i<s.size(); i++){
            if(s[i]!=n){
                zf++;
            }
            if(n=='0') n = '1';
            else n = '0';
        }
        n = '1';
        for(int i = 0; i<s.size(); i++){
            if(s[i]!=n){
                of++;
            }
            if(n=='0') n = '1';
            else n = '0';
        }
        return min(zf, of);
    }
};
