class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& a) {
        int maxx = -1;
        int n = a.size();
        vector<long long> conver;
        for(int i = 0; i<n; i++){
            maxx = max(maxx, a[i]);
            conver.push_back(a[i]+maxx);
        }
        vector<long long> res;
        long long last = 0;
        for(int i = 0; i<n; i++){
            res.push_back(last+conver[i]);
            last+=conver[i];
        }
        return res;
    }
};
