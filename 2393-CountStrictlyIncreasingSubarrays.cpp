class Solution {
public:
    long long countSubarrays(vector<int>& a) {
        int n = a.size();
        vector<long long> ress(n, 1);
        for(int i = 1; i<n; i++){
            if(a[i]>a[i-1]){
                ress[i]=ress[i-1]+1;
            }
        }
        //for(const auto& res : ress) cout<<res<<" "; cout<<endl;
        return accumulate(ress.begin(), ress.end(), 0LL);
    }
};
