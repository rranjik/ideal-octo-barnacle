class Solution {
public:
    int getJ(const vector<int>& m, int n){
        const int ori = n;
        int res = 0;
        vector<int> ds;
        if(!n) ds.push_back(m[0]);
        while(n){
            int d = n%10;
            ds.push_back(m[d]);
            n/=10;
        }
        for(int i = ds.size()-1; i>=0; i--){
            res*=10;
            res+=ds[i];
        }
        //cout<<ori<<" maps to "<<res<<endl;
        return res;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> p;
        for(int i = 0; i<nums.size(); i++){
            p.push_back({getJ(mapping, nums[i]), i});
        }
        sort(p.begin(), p.end());
        vector<int> res;
        for(int i = 0; i<p.size(); i++){
            res.push_back(nums[p[i].second]);
        }
        return res;
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b){
            return getJ(mapping, a)<getJ(mapping, b);
        });
        return nums;
    }
};
