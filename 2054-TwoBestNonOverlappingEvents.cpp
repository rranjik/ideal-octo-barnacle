class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size(); 
        sort(events.begin(), events.end());
        int res = 0;
        int maxx = 0;
        map<int, int> mp;
        int i = n-1;
        while(i>=0){
            auto it = mp.upper_bound(events[i][1]);
            maxx = max(maxx, events[i][2]);
            mp[events[i][0]] = maxx;
            res = max(maxx, res);
            if(it!=mp.end()){
                res = max(res, events[i][2]+it->second);
            }
            i--;
        }
        return res;
    }
};
