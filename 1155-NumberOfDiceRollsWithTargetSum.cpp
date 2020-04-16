namespace std{
    template<>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first)^(hash<int>()(p.second)>>1);
        }
    };
}
class Solution {
public:
    int f;
    int t;
    unordered_map<pair<int, int>, int> c;
    int dp(int d, int s){
        auto p = make_pair(d, s);
        if(c.find(p)!=c.end()) return c[p];
        if(d==0&&s==0){
            c[p] = 1;
            return 1;
        }
        if((d==0&&s!=0)||(d==0&&s<0)||(d!=0&&s==0)||(d!=0&&s<0)){
            c[p] = 0;
            return 0;
        }
        int res = 0;
        for(int i = 1; i<=f; i++){
            res = (res + (dp(d-1, s-i))%1000000007)%1000000007;
        }
        c[p] = res;
        return res;
    }
    int numRollsToTarget(int d, int f, int target) {
        this->f = f;
        this->t = target;
        return dp(d, t);
    }
};
