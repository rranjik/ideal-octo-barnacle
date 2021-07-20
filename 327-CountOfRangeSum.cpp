class Solution {
public:
    using it = vector<long long>::iterator;
    void mergesort(it l, it r, int& res){
        if(r-l<=1) return;
        auto m = l+(r-l)/2;
        mergesort(l, m, res);
        mergesort(m, r, res);
        for(auto i = l, j1 = m, j2 = m; i<m; i++){
            while(j1<r&&(*j1)-(*i)<lower) j1++;
            while(j2<r&&(*j2)-(*i)<=upper) j2++;
            res+=j2-j1;
        }
        inplace_merge(l, m, r);
    }
    int lower;
    int upper;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        //ps - prefix sums
        vector<long long> ps(nums.size()+1);
        long long prev = 0;
        for(int i = 0; i<nums.size(); i++){
            ps[i+1] = (prev+nums[i]);
            prev = ps[i+1];
        }
        int res = 0;
        mergesort(begin(ps), end(ps), res);
        return res;
    }
};
