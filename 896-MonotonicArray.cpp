class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int mi = true;
        for(int i = 0; mi&&i<A.size()-1; i++) {
            if(A[i]>A[i+1]) mi = false;
        }
        if(mi) return true;
        int md = true;
        for(int i = 0; md&&i<A.size()-1; i++) {
            if(A[i]<A[i+1]) md = false;
        }
        return md;
    }
};
