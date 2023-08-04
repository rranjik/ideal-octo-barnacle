class Solution {
public:
    void print(const vector<int>& v) {for(const auto& n : v)cout<<n<<" "; cout<<endl;}
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        //forward pile
        vector<int> fp;
        //reverse pile
        vector<int> rp;
        vector<int> ltr(n);
        vector<int> rtl(n);
        for(int i = 0; i<n; i++){
            auto v = nums[i];
            auto it = lower_bound(fp.begin(), fp.end(), v);
            if(it==fp.end()) fp.push_back(v);
            else *it = v;
            ltr[i] = fp.size();
        }
        reverse(begin(nums), end(nums));
        for(int i = 0; i<n; i++){
            auto v = nums[i];
            auto it = lower_bound(rp.begin(), rp.end(), v);
            if(it==rp.end()) rp.push_back(v);
            else *it = v;
            rtl[i] = rp.size();
        }
        //print(fp);
        //print(rp);
        //print(ltr);
        //print(rtl);
        int res = n;
        reverse(begin(rtl), end(rtl));
        for(int i = 0; i<n; i++){
            if(ltr[i]>1&&rtl[i]>1){
                res = min(res, n-ltr[i]-rtl[i]+1);
            }
        }
        return res;
    }
};
