class Solution {
public:
    int nearest(const vector<int>& n, int k){
        auto it = lower_bound(n.begin(), n.end(), k);
        int d = numeric_limits<int>::max();
        if(it!=n.end()){
            d = min(d, abs(*it - k ));
        }
        if(it!=n.begin()){
            it = prev(it);
            d = min(d, abs(*it - k ));
        }
        return d;
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int md = -1;
        vector<int> mdis;
        int n = nums1.size();
        for(int i = 0; i<n; i++){
            auto d = abs(nums1[i]-nums2[i]);
            if(md<d){
                md = d;
                mdis = vector<int>();
                mdis.push_back(i);
            }else if(md==d){
                mdis.push_back(i);
            }
        }
        if(md==0) return 0;
        //cout<<"max diff = "<<md<<endl;
        //cout<<"max diffed indices = ";
        //for(const auto& i : mdis){
        //    cout<<i<<" ";
        //}
        //cout<<endl;
        auto snums1 = nums1;
        sort(snums1.begin(), snums1.end());
        int wi = -1;
        int wd = -1;
        int mdim = numeric_limits<int>::max();
        for(const auto& i : mdis){
            auto d = nearest(snums1, nums2[i]);
            if(d<mdim){
                wi = i;
                wd = d;
                mdim = d;
            }
        }
        //cout<<"winning index = "<<wi<<endl;
        //cout<<"winning diff = "<<wd<<endl;
        int res{};
        int mod = 1e9+7;
        for(int i = 0; i<n; i++){
            if(i!=wi)
                res+=abs(nums1[i]-nums2[i]);
            else res+=wd;
            res%=mod;
        }
        return res;
    }
};
