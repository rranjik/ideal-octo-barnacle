class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        auto res = A;
        for(auto& r : res){
            reverse(begin(r), end(r));
        }
        for(auto& r : res){
            for(auto& n : r){
                if(n) n = 0;
                else n = 1;
            }
        }
        return res;
    }
};
