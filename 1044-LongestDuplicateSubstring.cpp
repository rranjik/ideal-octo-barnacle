class Solution {
public:
    bool verify(int i, int j, int m){
        for(int ii=i, jj = j, k = 0; k<m; k++, ii++, jj++){
            if(s[ii]!=s[jj]) return false;
        }
        return true;
    }
    int search(int m){
        if(!m) return -1;
        unordered_map<long long, vector<int>> seen;
        long long h = 0;
        long long mod = (long long)1125899839733759ll;
        for(int i = 0; i<m; i++){
            h*=26;
            h%=mod;
            h+=s[i];
            h%=mod;
        }
        seen.insert({h, {0}});
        long long mult = 1;
        for(int i = 0; i<m; i++) mult*=26, mult%=mod;
        for(int i = 1; i<=len-m; i++) {
            h = ( (h*26 - s[i-1]*mult) % mod + mod)%mod;
            h = (h+s[i+m-1]) % mod;
            if(seen.find(h)!=seen.end()) {
                for(const auto& ii : seen[h]) {
                    if(verify(ii, i, m)){
                        cout<<"found "<<endl;
                        return i; 
                    }
                }
                seen[h].push_back(i);
            }
            else seen.insert({h, {i}});
        }
        return -1;
    }
    vector<int> s;
    int len;
    string longestDupSubstring(string S) {
        len = S.length();
        if(!len) return "";
        for(const auto& c : S) s.push_back(c-'a');
        int left = 1;
        int right = len;
        while(left<=right){
            auto m = (right-left)/2+left;
            int r = search(m);
            if(r!=-1) left = m+1;
            else right = m-1;
        }
        cout<<"out left "<<left<<"; right "<<right<<endl;
        int start= search(left-1);
        if(start==-1) return "";
        return S.substr(start, left-1);
    }
};
