class Solution {
public:
    void dp(bitset<26> here, int i, int c, int& res, 
           const vector<bitset<26>>& v){
        //cout<<"i = "<<i<<"; c = "<<c
            //<<"; res = "<<res<<"; here "<<here<<endl;
        if(i==v.size()){
            res = max(res, c);
            return;
        }
        if(!(here&v[i]).any()){
            dp(here|v[i], i+1, c+a[i].length(), res, v);
        }
        dp(here, i+1, c, res, v);
    }
    vector<string> a;
    int maxLength(vector<string>& arr) {
        a = arr;
        vector<bitset<26>> tarr;
        vector<bool> tr(arr.size());
        for(int i = 0; i<arr.size(); i++){
            auto nn = bitset<26>();
            vector<int> f(26, 0);
            tarr.push_back(nn);
            for(const auto& c : arr[i]){
                if(f[c-'a']) {tr[i] = true;}
                tarr[i][c-'a'] = 1;
                f[c-'a']++;
            }
        }
        for(int i = tr.size()-1; i>=0; i--){
            if(tr[i]){
                tarr.erase(tarr.begin()+i);
                arr.erase(arr.begin()+i);
            }
        }
        a = arr;
        int res = 0;
        bitset<26> n;
        dp(n, 0, 0, res, tarr);
        return res;
    }
};
