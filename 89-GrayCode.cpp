class Solution {
public:
    vector<int> gc(int n){
        vector<int> res;
        if(n==0){
            res.push_back(0);
            return res;
        }
        else if(n==1){
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        else{
            auto pr = gc(n-1);
            auto p = pr;
            reverse(pr.begin(), pr.end());
            int f = pow(2,n-1);
            for(const auto& k : p){
                res.push_back(k);
            }
            for(const auto& k : pr){
                res.push_back(f+k);
            }
            return res;
        }
    }
    vector<int> grayCode(int n) {
        return gc(n);
    }
};
