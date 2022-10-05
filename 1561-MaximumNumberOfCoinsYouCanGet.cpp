class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(), p.end());
        int j = p.size()-2;
        int res{};
        for(int i = 0; i<p.size()/3; i++){
            res+=p[j];
            j-=2;
        }
        return res;
    }
};
