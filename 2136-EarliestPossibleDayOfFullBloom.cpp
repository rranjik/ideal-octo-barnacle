class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int, int>> m;
        for(int i = 0; i<pt.size(); i++){
            m.push_back({gt[i], pt[i]});
        }
        sort(begin(m), end(m));
        int res = 0;
        for(const auto& p : m){
            res = max(res, p.first) + p.second;
        }
        return res;
    }
};
