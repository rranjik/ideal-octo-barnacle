class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        reverse(b.begin(), b.end());
        int B = b.size();
        int res{};
        for(int i = 0; i<a.size(); i++){
            auto n = a[i];
            auto lb = lower_bound(b.begin(), b.end(), n);
            if(lb!=b.end()) {
                auto idx = lb-b.begin();
                int j = B-(idx+1);
                res = max(res, (j-i));
            }
        }
        return res;
    }
};
