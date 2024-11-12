class Solution {
public:
    unordered_map<int, unordered_map<bool, bool>> c;
    bool dp(int n, bool alice){
        if(c.find(n)!=c.end()&&c[n].find(alice)!=c[n].end()) return c[n][alice];
        //cout<<"n = "<<n<<(alice?" alice":" bob")<<endl;
        if(!n) return c[n][alice] = alice ? false : true;
        int nearsqrt = sqrt(n);
        if(nearsqrt*nearsqrt==n) return c[n][alice] = alice ? true : false;
        bool res = alice ? false: true;
        for(int i = nearsqrt; i>=1; i--){
            auto r = dp(n-i*i, !alice);
            if(alice) {
                res|=r;
                if(res) return c[n][alice] = res;
            }
            else {
                res&=r;
                if(!res) return c[n][alice] = res;
            }
        }
        return c[n][alice] = res;
    }
    bool winnerSquareGame(int n) {
        return dp(n, true);
    }
};
