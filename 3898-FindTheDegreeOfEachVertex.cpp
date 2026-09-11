
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res;
        for(const auto& r : matrix){
            int i = 0;
            for(const auto& v : r) i+=v;
            res.push_back(i);
        }
        return res;
    }

};
