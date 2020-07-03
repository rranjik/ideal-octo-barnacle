class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
       for(const auto& n : A){
           res.insert(upper_bound(res.begin(), res.end(), n*n), n*n);
           //res.push_back(n*n);
       }
        //sort(res.begin(), res.end());
        return res;
    }
};
