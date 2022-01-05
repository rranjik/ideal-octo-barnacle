class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> f(60);
        int res{};
        for(auto& t : time){
            t%=60;
            cout<<"t = "<<t<<endl;
            res+=f[(60-t)==60?0:60-t];
            f[t]++;
        }
        return res;
    }
};
