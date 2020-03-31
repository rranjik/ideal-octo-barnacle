class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        bitset<32> b;
        for(int i = 0; i<num+1; i++){
            b = i;
            res.push_back(b.count());
        }
        return res;
    }
};
