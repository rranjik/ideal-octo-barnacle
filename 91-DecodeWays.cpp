class Solution {
public:
    unordered_map<int, int> c;
    int dfs(int i, const string& s){
        if(i<s.size()&&s[i]=='0') return 0;
        if(i>=s.size()) return 1;
        if(c.find(i)!=c.end()) return c[i];
        int x = 0;
        int res = 0;
        int oi = i;
        while(i<s.size()){
            x*=10;
            x+=(s[i]-'0');
            if(x>26) break;
            cout<<"x = "<<x<<endl;
            res += dfs(i+1, s);
            i++;
        }
        return c[oi] = res;
    }
    int numDecodings(string s) {
        return dfs(0, s);
    }
};
