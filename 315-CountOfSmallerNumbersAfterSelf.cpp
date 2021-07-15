class Solution {
public:
    struct zipn{
        int i;
        int v;
        zipn(int _v, int _i):v(_v), i(_i) {}
        //ensure stable sort - though not seems to be required for this problem
        bool operator<(const zipn& z) const {if(v==z.v) return i<z.i; return v<z.v;}
    };
    using ziterator = vector<zipn>::iterator;
    //sorts [l, r)
    void mergesort(ziterator l, ziterator r, vector<int>& res){
        if(r-l<=1) return; //no elements b/w [l, r)
        auto m = l + (r-l)/2;
        mergesort(l, m, res);
        mergesort(m, r, res);
        for(auto i = l, j = m; i<m; i++){
            //j comes after i, and nums[j]<nums[i] - this is
            //what we care about
            while(j<r&&(*j).v<(*i).v) j++;
            //left = [5, 6, ...] and right = [2, 3, 7, ...] 
            //think how does 6 account for 2 and 3 ?
            //it's because every time we count 
            //all elemtns from m to j 
            //left = [5, 6, ...] and right = [2, 3, 7, ...] 
            //                                m     j
            res[(*i).i] += j-m;
        }
        inplace_merge(l, m, r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<zipn> zipped;
        for(int i = 0; i<nums.size(); i++){
            zipped.push_back(zipn(nums[i], i));
        }
        vector<int> res(nums.size());
        mergesort(begin(zipped), end(zipped), res);
        return res;
    }
};
