class Solution {
public:
    struct zipn{
        int i;
        int v;
        zipn(int _v, int _i):v(_v), i(_i) {}
        //make sure sort is stabe - don't know if it's really needed, just do
        bool operator<(const zipn& z) const {if(v==z.v)return i<z.i; return v<z.v;}
    };
    using zit = vector<zipn>::iterator;
    void mergesort(zit l, zit r, int& res){
        if(r-l<=1) return;
        auto m = l + (r-l)/2;
        mergesort(l, m, res);
        mergesort(m, r, res);
        for(auto i = l, j = m; i<m; i++){
            while(j<r&&(*i).v>2l*((*j).v)) j++;
            res+=j-m;
        }
        inplace_merge(l, m, r);
    }
    int reversePairs(vector<int>& nums) {
        vector<zipn> zipns;
        for(int i = 0; i<nums.size(); i++){
            zipns.push_back(zipn(nums[i], i));
        }
        int res = 0;
        mergesort(begin(zipns), end(zipns), res);
        return res;
    }
};
