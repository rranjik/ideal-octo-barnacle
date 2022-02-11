class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> e(n, vector<int>(2));
        for(int i = 0; i<n; i++){
            e.push_back({speed[i], efficiency[i]});
        }
        sort(begin(e), end(e), [](const vector<int>& a, const vector<int>& b){return a[1]>b[1];});
        priority_queue<int, vector<int>, greater<int>> q;
        using ull = unsigned long long;
        ull totalspeed = 0;
        ull res = 0;
        for(const auto& emp : e){
            if(q.size()==k) { totalspeed-=q.top(); q.pop(); }
            q.push(emp[0]);
            totalspeed+=emp[0];
            res = max(res, totalspeed*emp[1]);
        }
        return res%(ull(1e9+7));
    }
};
