class Solution {
public:
    using ll = long long;
    struct rabinkarp{
        ll mod = (1l<<31)-1;
        ll b = 256;
        ll bpowlen1modm = 1;
        ll h = 0;
        rabinkarp(int m){
            for(int i = 1; i<=m-1; i++){
                bpowlen1modm*=b;
                bpowlen1modm%=mod;
            }
        }
        void append(char c){
            ll v = static_cast<ll>(c);
            h*=b;
            h%=mod;
            h+=v;
            h%=mod;
        }
        void skip(char c){
            ll v = static_cast<ll>(c);
            ll tosub = (v*bpowlen1modm)%mod;
            h-=tosub;
            h+=mod;
            h%=mod;
        }
    };
    int search(int m){
        if(!m) return false;
        unordered_map<ll, vector<string>> seen;
        rabinkarp rk(m);
        for(int i = 0; i<m; i++) rk.append(s[i]);
        seen[rk.h].push_back(s.substr(0, m));
        //cout<<"rk("<<s.substr(0, m)<<") = "<<rk.h<<endl;
        for(int i = m; i<s.length(); i++){
            rk.skip(s[i-m]);
            rk.append(s[i]);
            auto thiss = s.substr(i-m+1, m);
            //cout<<"rk("<<thiss<<") = "<<rk.h<<endl;
            if(seen.find(rk.h)!=seen.end()){
                for(const auto& ss : seen[rk.h]){
                    if(ss==thiss) return i;
                }
            }
            seen[rk.h].push_back(thiss);
        }
        return -1;
    }
    string s;
    int longestRepeatingSubstring(string s) {
        this->s = s;
        unordered_map<string, int> f;
        int res = 0;
        int l = 1;
        int r = s.length();
        while(l<=r){
            int m = l+(r-l)/2;
            int i = search(m);
            if(i!=-1){
                //cout<<"m = "<<m<<" found @ i = "<<i<<endl;
                l = m+1;
            }else{
                //cout<<"m = "<<m<<" not found "<<endl;
                r = m-1;
            }
        }
        int start = search(l-1);
        if(start==-1) return 0;
        return l-1;
    }
};
