class Solution {
public:
    using it = vector<int>::iterator;
    int msort(it l, it r){
        if(r-l>1){
            cout<<"here "<<endl;
            auto m = l+(r-l)/2;
            auto left = msort(l, m);
            auto right = msort(m, r);
            auto res = 0;
            for(auto i = l, j = m; i<m; i++){
                while(j<r&&*i>*j){
                    j++;
                }
                res+=(j-m);
            }
            inplace_merge(l, m, r);
            return res+left+right;
        }return 0;
    }
    bool isIdealPermutation(vector<int>& A) {
        vector<int> a = A;
        auto g = msort(A.begin(), A.end());
        cout<<"g = "<<g<<endl;
        auto l = 0;
        for(int i = 0; i<A.size()-1; i++){
            if(a[i]>a[i+1]) l++;
        }
        cout<<"l = "<<l<<endl;
        return g==l;
    }
};
