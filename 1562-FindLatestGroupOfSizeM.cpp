struct unionfind{
    vector<int> p;
    vector<int> c;
    unionfind(int n){
        p = vector<int>(n);
        for(int i = 0; i<n; i++) p[i] = i;
        c = vector<int>(n, 1);
    }
    
    int uniun(int a, int b){
        auto ap = find(a);
        auto bp = find(b);
        if(ap!=bp){
            if(c[ap]>c[bp]){
                p[bp] = ap;
                c[ap]+=c[bp];
                return c[ap];
            }else{
                p[ap] = bp;
                c[bp]+=c[ap];
                return c[bp];
            }
        }return 0;
    }
    
    int find(int n){
        if(p[n]!=n) {
            p[n] = find(p[n]);
        }
        return p[n];
    }
};
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> s(n, 0);
        unordered_map<int, int> sc;
        unionfind uf = unionfind(n);
        int res{-1};
        for(int j = 0; j<arr.size(); j++){
            //cout<<"j = "<<j<<endl;
            auto i = arr[j]-1;
            //cout<<"i = "<<i<<endl;
            s[i] = 1;
            if(i-1>=0&&i+1<n&&s[i-1]&&s[i+1]){
                auto lp = uf.find(i-1);
                auto rp = uf.find(i+1);
                auto l = uf.c[lp];
                auto r = uf.c[rp];
                auto nn = l+r+1;
                sc[l]--;
                sc[r]--;
                sc[nn]++;
                if(!sc[l]) sc.erase(l);
                if(!sc[r]) sc.erase(r);
                uf.uniun(i, i-1);
                uf.uniun(i, i+1);
                //cout<<"combining both sides; deleted "<<l<<" (lp = "<<lp<<"), "<<r<<" (rp = "<<rp<<")"<<" created "<<nn<<endl;
            }else if(i-1>=0&&s[i-1]){
                auto lp = uf.find(i-1);
                auto l = uf.c[lp];
                auto nn = l+1;
                sc[l]--;
                sc[nn]++;
                if(!sc[l]) sc.erase(l);
                uf.uniun(i, i-1);
                //cout<<"combining left side; deleted "<<l<<" created "<<nn<<endl;
            }else if(i+1<n&&s[i+1]){
                auto rp = uf.find(i+1);
                auto r = uf.c[rp];
                auto nn = r+1;
                sc[r]--;
                sc[nn]++;
                if(!sc[r]) sc.erase(r);
                uf.uniun(i, i+1);
                //cout<<"combining right side; deleted "<<r<<" created "<<nn<<endl;
            }else{
                sc[1]++;
            }
            //for(const auto& it : sc){
            //    cout<<it.first<<" -> "<<it.second<<endl;
            //}
            if(sc.find(m)!=sc.end()){
                res = j+1;
            }
        }
        return res;
    }
};
