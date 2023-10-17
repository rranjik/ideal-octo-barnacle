class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& it, vector<int>& q) {
        sort(it.begin(), it.end());
        int n = it.size();
        vector<int> rm(n);
        vector<int> v(n);
        rm[0] = it[0][1];
        for(int i = 0; i<n; i++){
            v[i] = it[i][0];
        }
        for(int i = 1; i<n; i++){
            rm[i] = max(rm[i-1], it[i][1]);
        }
        vector<int> res;
        for(const auto& k : q){
            auto i = (upper_bound(v.begin(), v.end(), k)-v.begin());
            if(i){
                res.push_back(rm[i-1]);
            }else{
                res.push_back(0);
            }
        }
        return res;
    }
};
