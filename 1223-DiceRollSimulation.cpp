class key{
public:
    int n;
    int l;
    int c;
    key(int _n, int _l, int _c){
        n = _n; l = _l; c = _c;
    }
    bool operator==(const key& other)const{
        return n==other.n&&l==other.l&&c==other.c;
    }
};
namespace std{
    template<>
    struct hash<key>{
        size_t operator()(const key& k) const{
            return ((hash<int>()(k.n)^(hash<int>()(k.l)>>2))<<4)^(hash<int>()(k.c));
        }
    };
}
class Solution {
public:
    vector<int> rm;
    unordered_map<key, int> c;
    int dp(key k){
        if(c.find(k)!=c.end()) return c[k];
        if (k.n==0) {c[k] = 1; return c[k];}
        int res = 0;
        for(int i = 0; i<6; i++){
            if(i!=k.l) {
                res = (res+dp(key(k.n-1, i, 1)))%1000000007;
            } else if(k.c<rm[i]){
                res = (res+dp(key(k.n-1, i, k.c+1)))%1000000007;
            }
        }
        c[k]= res;
        return c[k];
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        rm = rollMax;
        return dp(key(n, -1, 0));
    }
};
