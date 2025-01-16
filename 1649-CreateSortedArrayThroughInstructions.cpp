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
      for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = (t[p] + t[p^1]);
    }
    
    int get(int i){
        return t[i+n];
    }

    int query(int l, int r) {  // sum on interval [l, r)
        //cout<<"l = "<<l<<" r = "<<r;
      int res = 0;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
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
    
    int createSortedArray(vector<int>& ins) {
        int sz = *max_element(ins.begin(), ins.end())+1;
        SegTree t(sz);
        int res = 0;
        int mod = 1e9+7;
        for(const auto& a : ins){
            //t.print();
            auto less = t.query(0, a);
            auto more = t.query(a+1, sz);
            t.modify(a, t.get(a)+1);
            res += min(less, more);
            res %= mod;
        }
        //t.print();
        return res;
    }
};
