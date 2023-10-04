class Solution {
public:
    void print(const vector<int>& v){
        for(const auto& n : v) cout<<n<<" "; cout<<endl;
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> r(n);
        vector<int> l(n);
        vector<int> ps(n);
        int prev = -1;
        for(int i = 0; i<n; i++){
            if(s[i]=='|'){
                l[i] = i;
                prev = i;
            }else{
                l[i] = prev;
            }
        }
        prev = -1;
        for(int i = n-1; i>=0; i--){
            if(s[i]=='|'){
                r[i] = i;
                prev = i;
            }else{
                r[i] = prev;
            }
        }
        if(s[0]=='*')
            ps[0] = 1;
        for(int i = 1; i<n; i++){
            if(s[i]=='*'){
                ps[i] = ps[i-1]+1;
            }else{
                ps[i] = ps[i-1];
            }
        }
        //print(l);
        //print(r);
        //print(ps);
        vector<int> res;
        for(const auto& q : queries){
            auto s = q[0];
            auto e = q[1];
            auto f = r[s]; auto m = l[e];
            if(f==-1||m==-1||f>=m+1){
                //cout<<"contuning "<<endl;
                res.push_back(0);
                continue;
            }
            //cout<<"s = "<<s<<" f = "<<f<<" e = "<<e<<" m = "<<m<<endl;
            res.push_back(ps[m]-ps[f]);
        }
        return res;
    }
};
