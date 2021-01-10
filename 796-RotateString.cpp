class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size()) return false;
        if(!A.size()) return true;
        int len = A.size();
        for(int s = 0; s<len; s++){
            bool mismatch = false;
            int i = 0;
            for(;!mismatch&&i<len; i++){
                if(A[(i+s)%len]!=B[i]) mismatch = true;
            }
            if(i==len) return true;
        }
        return false;
    }
};
