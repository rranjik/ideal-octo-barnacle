class Solution {
public:
    bool isDecomposable(string s) {
        s.push_back('*');
        auto cnt = 1;
        int m2 = 0;
        for(int i = 1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else {
                if(cnt%3==1) return false;
                else if(cnt%3==2) {
                    m2++;
                    if(m2>1) return false;
                }
                cnt = 1;
            }
        }
        return m2==1;
    }
};
