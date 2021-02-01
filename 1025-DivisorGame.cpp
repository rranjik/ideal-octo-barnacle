class state{
public:
    int n;
    bool p;
    state(int _n, bool _p):n(_n), p(_p){}
    bool operator==(const state& s) const{
        return n==s.n&&p==s.p;
    }
};
namespace std{
    template <>
    struct hash<state>{
        size_t operator()(const state& s) const {
            return (hash<int>()(s.n)^0x10392038)^
                (hash<bool>()(s.p)^0x29483027);
        }
    };
}
class Solution {
public:
    unordered_map<state, bool> c;
    bool dp(int n, bool a){
        auto s = state(n, a);
        if(c.find(s)!=c.end()) return c[s];
        if(n==1&&!a) return true;
        if(n==1&&a) return false;
        auto res = false;
        int x = n-1;
        if(a) {
            res = false;
            while(!res&&x>0){
                if(n%x == 0){
                    res|=dp(n-x, !a);
                }
                x--;
            }
        }
        else {
            res = true;
            while(res&&x>0){
                if(n%x == 0){
                    res&=dp(n-x, !a);
                }
                x--;
            }
        }
        c[s] = res;
        return res;
    }
    bool divisorGame(int N) {
        return dp(N, true);
    }
};
