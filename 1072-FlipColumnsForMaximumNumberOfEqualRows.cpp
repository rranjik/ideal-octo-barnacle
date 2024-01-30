class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> f;
        for(const auto& r : matrix){
            string dist1;
            string dist0;
            for(const auto& n : r){
                dist0 += (n==1?'1':'0');
                dist1 += (n==1?'0':'1');
            }
            f[dist0]++;
            f[dist1]++;
        }
        int res = -1;
        for(const auto& it : f){
            res = max(res, it.second);
        }
        return res;
    }
};
