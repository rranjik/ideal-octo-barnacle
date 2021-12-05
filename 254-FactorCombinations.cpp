class Solution {
public:
    set<multiset<int>> factors(int n){
        if(n==2&&t!=n){
            return {{2}};
        }
        set<multiset<int>> res;
        for(int i = 2; i<n; i++){
            if(n%i==0){
                auto factori = factors(n/i);
                for(auto f : factori) {
                    f.insert(i);
                    res.insert(f);
                }
            }
        }
        if(t!=n) res.insert({n});
        return res;
    }
    int t;
    vector<vector<int>> getFactors(int n) {
        t = n;
        if(n==1) return {};
        vector<vector<int>> res;
        auto r = factors(n);
        for(const auto& m : r){
            vector<int> v;
            for(const auto& n : m){
                v.push_back(n);
            }
            res.push_back(v);
        }
        return res;
    }
};
