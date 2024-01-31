class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9+7;
        //seats
        vector<int> ss;
        for(int i = 0; i<corridor.size(); i++){
            auto c = corridor[i];
            if(c=='S'){
                ss.push_back(i);
            }
        }
        if(ss.size()%2||ss.size()==0) return 0;
        
        int prev = ss[1];
        long long res = 1;
        for(int i = 2; i<ss.size(); i+=2){
            int len = ss[i]-prev;
            res = (res*len)%mod;
            prev = ss[i+1];
        }
        return res;
    }
};
