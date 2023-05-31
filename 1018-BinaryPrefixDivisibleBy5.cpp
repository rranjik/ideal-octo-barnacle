class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int v{};
        vector<bool> res;
        for(int i = 0; i<A.size(); i++){
            v*=2;
            v%=5;
            v+=A[i];
            v%=5;
            if(v) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};
