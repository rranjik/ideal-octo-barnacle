class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<bitset<32>> b;
        for(const auto& n : arr){
            b.push_back(bitset<32>(n));
        }
        sort(begin(b), end(b), [](bitset<32> x, bitset<32> y){
            if(x.count() == y.count()){
                return (int)(x.to_ulong())<(int)(y.to_ulong());
            }else return x.count()<y.count();
        });
        vector<int> res;
        for(const auto bb : b){
            res.push_back((int)(bb.to_ulong()));
        }
        return res;
    }
};
