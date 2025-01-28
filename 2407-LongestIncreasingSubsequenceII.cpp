struct SegTree{
    SegTree(int _n){
        n = _n;
        t = vector<int>(2*n, 0);
    }
    int n;  // array size
    vector<int> t;

    //void build() {  // build the tree
    //  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
    //}

    void modify(int p, int value) {  // set value at position p
      for (t[p += n] = value; p >= 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
    }

    int query(int l, int r) {  // sum on interval [l, r)
        //cout<<"l = "<<l<<" r = "<<r;
      int res = 0;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
      }
        //cout<<" res = "<<res<<endl;
      return res;
    }
    void print(){
        for(int i = n; i<t.size(); i++){
            cout<<t[i]<<" ";
        }
        cout<<endl;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        auto sz = *max_element(nums.begin(), nums.end());
        SegTree t(sz+1);
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            //t.print();
            auto hres = t.query(max(0, nums[i]-k), nums[i])+1;
            //cout<<nums[i]<<" "<<res<<endl;
            t.modify(nums[i], hres);
            res = max(res, hres);
        }
        //t.print();
        return res;
    }
};
//class Solution {
//public:
//    unordered_map<int, unordered_map<int, int>> c;
//    int dp(int i, int l){
//        if(c.find(i)!=c.end()&&c[i].find(l)!=c[i].end()) return c[i][l];
//        if(i<0) return c[i][l] = 0;
//        auto h = a[i];
//        int res = 0;
//        if(h>=l||(l-h>k)){
//            res = dp(i-1, l);
//        }else{
//            res = max({dp(i-1, l), dp(i-1, h)+1});
//        }
//        return c[i][l] = res;
//    }
//    int k;
//    vector<int> a;
//    int lengthOfLIS(vector<int>& nums, int k) {
//        this->k = k;
//        auto n = nums.size();
//        a = nums;
//        int res = 0;
//        for(int i = a.size()-1; i>=0; i--){
//            auto w = dp(i-1, a[i]);
//            if(i+1<res) break;
//            if(res<w){
//                //cout<<"max at "<<i<<" a[i] = "<<a[i]<<endl;
//                res = w;
//            }
//        }
//        return res+1;
//    }
//};
