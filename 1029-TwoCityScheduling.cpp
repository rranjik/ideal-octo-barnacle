namespace std {
    template<>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p) const{
            return (hash<int>()(p.first)^0x29739283)^
            (hash<int>()(p.second)^0x92859280);
        }
    };
}
class Solution {
public:
    using pii = pair<int, int>;
    unordered_map<pair<int, int>, int> c;
    int dp(int i, int a){
        auto p = make_pair(i, a);
        if(c.find(p)!=c.end()) return c[p];
        if(i==2*n) {
            c[p] = 0;
            return 0;
        }
        int b = i-a;
        auto res = 0;
        if(b>=n){
            res = dp(i+1, a+1)+costs[i][0];
            c[p] = res;
            return res;
        }else if(a>=n){
            res = dp(i+1, a)+costs[i][1];
            c[p] = res;
            return res;
        }
        res = min(dp(i+1, a)+costs[i][1], dp(i+1, a+1)+costs[i][0]);
        c[p] = res;
        return res;
    }
    vector<vector<int>> costs;
    int n;
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), 
             [](const vector<int>& a, const vector<int>& b){
                 return a[0] - a[1] < b[0] - b[1];
             });
        n = costs.size()/2;
        int res = 0;
        for(int i = 0; i<n; i++)
            res+=costs[i][0]+costs[i+n][1];
        return  res;
        //if(!n) return 0;
        //this->costs = costs;
        //return  dp(0, 0);
    }
};
