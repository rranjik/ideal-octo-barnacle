class Solution {
public:
    bool dfs(int i, vector<int>& a){
        if(i==n) {
            return (a[0]==a[1])&&(a[1]==a[2])&&(a[2]==a[3]);
        }
        bool res = false;
        for(int j = 0; j<4; j++){
            if(a[j]+s[i]>sum/4) continue;
            a[j]+=s[i];
            res |= dfs(i+1, a);
            if(res) return true;
            a[j]-=s[i];
        }
        return res;
    }
    vector<int> s;
    int n;
    int sum = 0;
    bool makesquare(vector<int>& matchsticks) {
        s = matchsticks;
        sort(s.begin(), s.end(), greater<int>());
        sum = accumulate(s.begin(), s.end(), 0);
        if(sum%4) return false;
        for(const auto& a : s) if(a>sum/4) return false;
        n = s.size();
        vector<int> sides(4);
        return dfs(0, sides);
    }
};
