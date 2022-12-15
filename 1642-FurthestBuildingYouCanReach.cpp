struct node{
    int c{-1}; int b{-1}; int l{-1};
    node(int _c, int _b, int _l): c(_c), b(_b), l(_l) {}
    bool operator==(const node& n) const {
        return c==n.c&&b==n.b&&l==n.l;
    }
};
namespace std{
    template <>
    struct hash<node>{
        size_t operator()(const node& n) const {
            return (hash<int>()(n.c))^
                ((hash<int>()(n.b)<<1)>>1)^
                (hash<int>()(n.l)<<1);
        }
    };
}
class Solution {
public:
    unordered_map<node, int> ca;
    int cm{};
    int dp(int c, int b, int l){
        auto n = node(c, b, l);
        if(ca.find(n)!=ca.end()) return ca[n];
        if(c==h.size()-1) {
            ca[n] = c;
            cm = max(cm, ca[n]);
            return ca[n];
        }
        if(h[c]>=h[c+1]) {
            ca[n] = dp(c+1, b, l);
            cm = max(cm, ca[n]);
            return ca[n];
        }
        int res = c;
        if(b>=(h[c+1]-h[c])&&cm<h.size()-1){
            res = max(res, dp(c+1, b-(h[c+1]-h[c]), l));
        }
        if(l&&cm<h.size()-1){
            res = max(res, dp(c+1, b, l-1));
        }
        ca[n] = res;
        cm = max(cm, ca[n]);
        return ca[n];
    }
    vector<int> h;
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        h = heights;
        return dp(0, bricks, ladders);
    }
};
