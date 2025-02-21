class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(), e.end());
        int i = n-1;
        int res = 0;
        int maxx = -1;
        map<int, int> m;
        while(i>=0){
            auto st = e[i][0]; auto en = e[i][1];
            auto ct = e[i][2];
            auto it = m.upper_bound(en);
            res = max(res, ct);
            maxx = max(maxx, ct);
            m[st] = maxx;
            if(it!=m.end()){
                res = max(res, ct+it->second);
            }
            i--;
        }
        return res;
    }
};
