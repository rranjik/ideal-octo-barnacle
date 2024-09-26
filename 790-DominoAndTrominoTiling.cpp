class Solution {
public:
    int mod = 1e9+7;
    unordered_map<int, int> c;
    int numTilings(int n) {
        if(c.find(n)!=c.end()) return c[n];
        if(n==0) return c[n] = 1;
        if(n==1) return c[n] = 1;
        if(n==2) return c[n] = 2;
        if(n==3) return c[n] = 5;
        return c[n] = (((numTilings(n-1)*2)%mod)+numTilings(n-3))%mod;
    }
};
