class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(!ops.size()) return m*n;
        int mr = numeric_limits<int>::max();
        int mc = numeric_limits<int>::max();
        for(int i = 0; i<ops.size(); i++){
            mr = min(mr, ops[i][0]);
            mc = min(mc, ops[i][1]);
        }
        return mr*mc;
    }
};
