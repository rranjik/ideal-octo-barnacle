class Solution {
public:
    bool checkOnesSegment(string s) {
        int fz = -1;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='0') {
                fz = i;
                break;
            }
        }
        if(fz==-1) return true;
        for(int i = fz+1; i<s.size(); i++){
            if(s[i]=='1') return false;
        }
        return true;
    }
};
