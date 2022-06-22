class Solution {
public:
    unordered_map<string, unordered_map<bool, bool>> c;
    bool dp(string s, bool f){
        if(c.find(s)!=c.end()){
            if(c[s].find(f)!=c[s].end()) return c[s][f];
        }
        //cout<<(f?"first":"second")<<" "<<s<<endl;
        if(f){
            int pos = 0;
            int last_pos = 0;
            int res = false;
            while((pos=s.find("++", last_pos))!=string::npos){
                last_pos++;
                auto sc = s;
                sc[pos] = '-';
                sc[pos+1] = '-';
                res|=dp(sc, !f);
            }
            c[s][f] = res;
            return res;
        }
        int pos = 0;
        int last_pos = 0;
        int res = true;
        while((pos=s.find("++", last_pos))!=string::npos){
            last_pos++;
            auto sc = s;
            sc[pos] = '-';
            sc[pos+1] = '-';
            res&=dp(sc, !f);
        }
        c[s][f] = res;
        return res;
    }
    bool canWin(string s) {
        return dp(s, true);
    }
};
