class Solution {
public:
    using pii = pair<int, int>;
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int res = 0;
        auto m = numeric_limits<int>::min();
        for(const auto& n : nuts){
            auto d = abs(n[0]-tree[0])+abs(n[1]-tree[1]);
            res+=2*d;
            m = max(m, d - (abs(n[0]-squirrel[0])+abs(n[1]-squirrel[1])));
        }
        return res-m;
    }
};
