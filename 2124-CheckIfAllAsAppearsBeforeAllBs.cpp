class Solution {
public:
    bool checkString(string s) {
        int lasta = -1;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i]=='a') {
                lasta = i;
                    break;
            }
        }
        if(lasta==-1) return true;
        for(int i = lasta-1; i>=0; i--){
            if(s[i]=='b') {
                return false;
            }
        }
        return true;
    }
};
