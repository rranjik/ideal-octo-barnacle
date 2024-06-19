class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> ps(n+1);
        int t = arr[0];
        for(int i = 1; i<arr.size(); i++){
            t+=arr[i];
            ps[i] = ps[i-1]+arr[i-1];
        }
        for(const auto& a : ps) cout<<a<<" "; cout<<endl;
        int res = arr[n-1];
        if(t==target) return arr[n-1];
        for(int i = n-1; i>=0; i--){
            cout<<"i = "<<i<<endl;
            int psi = ps[i];
            double ex = ((double)target-psi-1)/(n-i);
            cout<<"target/psi = "<<target-psi<<endl;
            cout<<"ex = "<<ex<<endl;
            if(arr[i]>=ex&&((i-1)>=0?ex>=arr[i-1]:ex>=0)) {
                int fex = floor(ex);
                int cex = ceil(ex);
                int wfex = abs(psi+(n-i)*fex - target);
                int wcex = abs(psi+(n-i)*cex - target);
                int eex = wfex > wcex ? cex : fex;
                cout<<"with floor = "<<wfex<<" with ceil = "<<wcex<<endl;
                res = (int)min((double)res, floor(eex));
            }
        }
        return res;
    }
};
