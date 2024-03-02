class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int m = 1<<n;
        //vector<int> hitm(n);
        //for(int i = 0; i<arr.size(); i++){
        //    auto a = arr[i];
        //    for(const auto& c : a){
        //        hitm[i]|=(c-'a');
        //    }
        //}
        int res = 0;
        for(int i = 0; i<m; i++){
            vector<int> f(26);
            int rres = 0;
            for(int j = 0; j<n; j++){
                if((i&(1<<j))==0)continue;
                rres+=arr[j].size();
                for(const auto& c : arr[j]){
                    f[c-'a']++;
                    if(f[c-'a']>=2) break;
                }
            }
            bool okay = true;
            for(const auto& x : f) if(x>1) okay = false;
            //cout<<i<<": ";
            //for(const auto& x : f) cout<<x<<"."; cout<<endl;
            if(okay)
            res = max(res, rres);
        }
        return res;
    }
};
