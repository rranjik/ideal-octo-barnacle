class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length);
        for(const auto& u : updates){
            auto s = u[0];
            auto e = u[1];
            res[s]+=u[2];
            if(e+1<res.size()) res[e+1]+=(-u[2]);
        }
        for(int i = 1; i<res.size(); i++){
            res[i]+=res[i-1];
        }
        return res;
    }
};
