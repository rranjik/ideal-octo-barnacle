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
    int n;
    unordered_map<pair<int, int>, int> ca;
    int dp(int c, int cl){
        auto p = make_pair(c, cl);
        if(ca.find(p)!=ca.end()) return ca[p];
        if(c==n){
            ca[p] = 0;
            return 0;
        }
        if(c>n){
            ca[p] = 20000;
            return 20000;
        }
        int res = min(dp(2*c, c)+2, cl?dp(c+cl, cl)+1:numeric_limits<int>::max());
        ca[p] = res;
        return res;
    }
    int minSteps(int n) {
        this->n = n;
        return dp(1, 0);
    }
};
