class Solution {
public:
    string rotate(string s, int r){
        int m = s.length();
        r%=m;
        if(r==0) return s;
        string res = s;
        int n = r;
        for(int i = 0; i<s.length(); i++){
           auto pos = (i+r)%m;
           res[pos] = s[i];
        }
        return res;
    }
    string add(string s, int r){
        r%=10;
        for(int i = 1; i<s.length(); i+=2){
            int n = s[i]-'0';
            int nn = (n+r)%10;
            s[i] = static_cast<char>('0'+nn);
        }
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);
        unordered_set<string> seen;
        seen.insert(s);
        string res = string(s.length(), '9');
        //cout<<"initially "<<res<<endl;
        while(!q.empty()){
            auto l = q.size();
            for(int i = 0; i<l; i++){
                auto h = q.front(); q.pop();
                //cout<<"here = "<<h<<endl;
                res = min(res, h);
                auto r = rotate(h, b);
                //cout<<h<<" rotated "<<b<<" times is "<<r<<endl;
                if(seen.find(r)==seen.end()) {
                    seen.insert(r);
                    q.push(r);
                }
                auto c = add(h, a);
                //cout<<h<<" + "<<a<<" is "<<c<<endl;
                if(seen.find(c)==seen.end()) {
                    seen.insert(c);
                    q.push(c);
                }
            }
        }
        return res;
    }
};
