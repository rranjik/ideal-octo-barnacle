class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int>> poss;
        pair<int, int> res({1e9, 1e9});
        int diff = 0;
        for(int i = 0; i<nums.size(); i++){
            for(const auto& m : nums[i]){
                poss.push_back({m, i});
                res.first = min(res.first, m);
                res.second = max(res.second, m);
            }
        }
        diff = res.second-res.first;
        sort(poss.begin(), poss.end());
        int i = 0;
        int j = 0;
        vector<int> f(n);
        int seen = 0;
        int nn = poss.size();
        //for(const auto& p : poss) cout<<"{"<<p.first<<", "<<p.second<<"}"<<", "; 
        //cout<<endl;
        while(j<nn){
            if(f[poss[j].second]==0){
                seen++;
            }
            f[poss[j].second]++;
            while(seen==n){
                auto maxx = poss[j].first;
                auto minn = poss[i].first;
                if(diff>maxx-minn){
                    diff = maxx-minn;
                    res = {maxx, minn};
                }
                f[poss[i].second]--;
                if(f[poss[i].second]==0) seen--;
                i++;
            }
            j++;
        }
        return {res.first, res.second};
    }
};
